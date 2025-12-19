#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
#include <atcoder/lazysegtree>
using namespace atcoder;

using ll=long long;
#define int ll

constexpr int INF = std::numeric_limits<int>::max()/4; // 約2e18


// テンプレ
using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

using F=int;
constexpr F ID=numeric_limits<F>::max()/4;
// constexpr F ID=-1;
S mapping(F f,S x){return (f==ID)?x:(f+x);}
F composition(F f,F g){return f==ID?g:f;}
F id(){return ID;}



// segtree (max/min/sum)
using S_max = int;
S_max op_max(S_max a, S_max b){ return max(a,b); }
S_max e_max(){ return LLONG_MIN/4; }

using S_min = int;
S_min op_min(S_min a, S_min b){ return min(a,b); }
S_min e_min(){ return LLONG_MAX/4; }

// 注: sum 演算はオーバーフローしうるので入力範囲に注意
using S_sum = int;
S_sum op_sum(S_sum a, S_sum b){ return a + b; }
S_sum e_sum(){ return 0; }



// pair<int,int> の例
// (value, index) を要素として value の最大値を返す (同値なら小さい index)
using S_pair = pair<int,int>;
S_pair op_pair_max(S_pair a, S_pair b){
    if(a.first != b.first) return (a.first > b.first) ? a : b;
    return (a.second < b.second) ? a : b;
}
S_pair e_pair_max(){ return {LLONG_MIN/4, LLONG_MAX/4}; }



// lazy_segtree
// no-op（何もしない操作）は mapping(id(), x) == x を満たす必要がある。
// mapping(F f, S x) は「操作 f を状態 x に適用した結果」を返す。
// composition(f,g) は「f を g の後に適用した合成」を返す必要があり、
// mapping(f, mapping(g,x)) == mapping(composition(f,g), x) が成立しなければならない。
//
// よくある誤り: F を bool にして id()=false、composition = (f || g) にするパターン。
//  - この場合 id() が no-op にならず（false を適用すると上書きされる）、
//    f||g は順序を無視するため "後から来た上書き" を表現できない。
//
// 対処（簡潔）:
//  - assign 系（上書き）では sentinel を使う（例: F=int, id()=INF）。
//      mapping: (f == INF) ? x : assign f
//      composition: (f == INF) ? g : f  // 後の操作 f が優先
//  - あるいは std::optional を使い nullopt を no-op にする。
//
// 補足: 区間加算（add）の場合は単位元 0 が存在するため sentinel は不要。
//  mapping(f,x)=f+x, composition(f,g)=f+g, id()=0 がそのまま成立する。


// 区間加算・区間最小値取得
// op_add_min: 区間の最小値を返す結合関数
// e_add_min: 単位元（非常に大きな値）
// mapping_add_min: ライジング関数 f を要素 x に適用する（ここでは加算 f + x）
// composition_add_min: 作用を合成するときのルール（add は加算で合成）
// id_add_min: 単位元（何もしない更新）
using S_add_min = int;
using F_add_min = int;
S_add_min op_add_min(S_add_min a, S_add_min b){ return std::min(a,b); }
S_add_min e_add_min(){ return INF; }
// 注意: mapping_add_min は f + x を行うため、f と x の加算でオーバーフローする可能性があります
S_add_min mapping_add_min(F_add_min f, S_add_min x){ return f + x; }
F_add_min composition_add_min(F_add_min f, F_add_min g){ return f + g; }
F_add_min id_add_min(){ return 0; }

// 区間加算・区間最大値取得
// op_add_max: 区間の最大値を返す結合関数
// e_add_max: 単位元（非常に小さな値）
// mapping_add_max: 要素への加算（f + x）
// composition_add_max: 加算の合成
// id_add_max: 単位元
using S_add_max = int;
using F_add_max = int;
S_add_max op_add_max(S_add_max a, S_add_max b){ return std::max(a,b); }
S_add_max e_add_max(){ return -INF; }
// 注意: mapping_add_max でも加算によりオーバーフローする可能性があります
S_add_max mapping_add_max(F_add_max f, S_add_max x){ return f + x; }
F_add_max composition_add_max(F_add_max f, F_add_max g){ return f + g; }
F_add_max id_add_max(){ return 0; }

// 区間加算・区間和取得
// S_add_sum: 要素は (value, size)
// op_add_sum: 2つのセグメントを結合して和とサイズを返す
// mapping_add_sum: 区間に加算 f を適用 -> value += f * size
//   ※ 注意: f * size の積はオーバーフローする可能性があります。中間を __int128 で扱うことを推奨します。
struct S_add_sum { int value; int size; };
using F_add_sum = int;
S_add_sum op_add_sum(S_add_sum a, S_add_sum b){ return {a.value + b.value, a.size + b.size}; }
S_add_sum e_add_sum(){ return {0, 0}; }
S_add_sum mapping_add_sum(F_add_sum f, S_add_sum x){ return { x.value + f * x.size, x.size }; }
F_add_sum composition_add_sum(F_add_sum f, F_add_sum g){ return f + g; }
F_add_sum id_add_sum(){ return 0; }

// 区間変更・区間最小値取得
// F_assign_min は assign 値をそのまま格納する long long。
// mapping_assign_min は f が ID（no-op）なら何もしない、そうでなければ区間を f で上書きします。
// 注意: この実装では特定の sentinel 値 (ASSIGN_ID_min) を no-op として使っています。
//         より確実に衝突を避けたい場合は F を {bool have; int v;} のような型にして no-op をフラグで表現する方が安全です。
using S_assign_min = int;
using F_assign_min = int;
static const F_assign_min ASSIGN_ID_min = INF;
S_assign_min op_assign_min(S_assign_min a, S_assign_min b){ return std::min(a,b); }
S_assign_min e_assign_min(){ return INF; }
S_assign_min mapping_assign_min(F_assign_min f, S_assign_min x){ return (f == ASSIGN_ID_min) ? x : f; }
F_assign_min composition_assign_min(F_assign_min f, F_assign_min g){ return (f == ASSIGN_ID_min) ? g : f; }
F_assign_min id_assign_min(){ return ASSIGN_ID_min; }

// 区間変更・区間最大値取得
// mapping_assign_max: assign 用の更新。sentinel を用いた no-op 判定を行う。
using S_assign_max = int;
using F_assign_max = int;
static const F_assign_max ASSIGN_ID_max = INF;
S_assign_max op_assign_max(S_assign_max a, S_assign_max b){ return std::max(a,b); }
S_assign_max e_assign_max(){ return -INF; }
S_assign_max mapping_assign_max(F_assign_max f, S_assign_max x){ return (f == ASSIGN_ID_max) ? x : f; }
F_assign_max composition_assign_max(F_assign_max f, F_assign_max g){ return (f == ASSIGN_ID_max) ? g : f; }
F_assign_max id_assign_max(){ return ASSIGN_ID_max; }

// 区間変更・区間和取得
// S_assign_sum: (value, size)
// mapping_assign_sum: f が ID でない場合に範囲を f に上書きする -> value = f * size
// 注意: f * size はオーバーフローする可能性があるため中間を __int128 で計算して clamp するのが安全です。
struct S_assign_sum { int value; int size; };
using F_assign_sum = int;
static const F_assign_sum ASSIGN_ID_sum = INF;
S_assign_sum op_assign_sum(S_assign_sum a, S_assign_sum b){ return {a.value + b.value, a.size + b.size}; }
S_assign_sum e_assign_sum(){ return {0,0}; }
S_assign_sum mapping_assign_sum(F_assign_sum f, S_assign_sum x){ if(f != ASSIGN_ID_sum) x.value = f * x.size; return x; }
F_assign_sum composition_assign_sum(F_assign_sum f, F_assign_sum g){ return (f == ASSIGN_ID_sum) ? g : f; }
F_assign_sum id_assign_sum(){ return ASSIGN_ID_sum; }



signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vector<int> a={3,1,4,1,5,9,2};
    int n=a.size();


    segtree<S_max, op_max, e_max> segMax(n);
    segtree<S_min, op_min, e_min> segMin(n);
    segtree<S_sum, op_sum, e_sum> segSum(n);
    for(int i=0;i<n;i++){ segMax.set(i,a[i]); segMin.set(i,a[i]); segSum.set(i,a[i]); }
    // segtree<S_max, op_max, e_max> segMax(a); のように配列を渡して初期化することも可能

    cout << "segtree max [1,5): " << segMax.prod(1,5) << endl;
    cout << "segtree min [0,7): " << segMin.prod(0,7) << endl;
    cout << "segtree sum [2,6): " << segSum.prod(2,6) << endl;



    // pair<int,int> を要素とする segtree
    segtree<S_pair, op_pair_max, e_pair_max> segPair(n);
    for(int i=0;i<n;i++) segPair.set(i, {a[i], i});
    auto p = segPair.prod(0,n);
    cout << "pair max (value,index): (" << p.first << "," << p.second << ")" << endl;



    // lazy examples
    // 区間加算・区間最小値取得
    atcoder::lazy_segtree<S_add_min, op_add_min, e_add_min, F_add_min, mapping_add_min, composition_add_min, id_add_min> lzA(n);
    for(int i=0;i<n;i++) lzA.set(i, a[i]);
    lzA.apply(0,3, 5); // +5 to [0,3)
    cout << "add+min prod(0,3): " << lzA.prod(0,3) << endl;

    // 区間加算・区間最大値取得
    atcoder::lazy_segtree<S_add_max, op_add_max, e_add_max, F_add_max, mapping_add_max, composition_add_max, id_add_max> lzB(n);
    for(int i=0;i<n;i++) lzB.set(i, a[i]);
    lzB.apply(2,6, 7);
    cout << "add+max prod(2,6): " << lzB.prod(2,6) << endl;

    // 区間加算・区間和取得
    vector<S_add_sum> initC(n);
    for(int i=0;i<n;i++) initC[i] = {a[i], 1};
    atcoder::lazy_segtree<S_add_sum, op_add_sum, e_add_sum, F_add_sum, mapping_add_sum, composition_add_sum, id_add_sum> lzC(initC);
    lzC.apply(1,4, 3);
    cout << "add+sum total: " << lzC.prod(0,n).value << endl;

    // 区間変更・区間最小値取得
    atcoder::lazy_segtree<S_assign_min, op_assign_min, e_assign_min, F_assign_min, mapping_assign_min, composition_assign_min, id_assign_min> lzD(n);
    for(int i=0;i<n;i++) lzD.set(i, a[i]);
    lzD.apply(3,5, 0); // set [3,5) to 0
    cout << "assign+min prod(0,7): " << lzD.prod(0,7) << endl;

    // 区間変更・区間最大値取得
    atcoder::lazy_segtree<S_assign_max, op_assign_max, e_assign_max, F_assign_max, mapping_assign_max, composition_assign_max, id_assign_max> lzE(n);
    for(int i=0;i<n;i++) lzE.set(i, a[i]);
    lzE.apply(1,3, 10);
    cout << "assign+max prod(0,7): " << lzE.prod(0,7) << endl;

    // 区間変更・区間和取得
    vector<S_assign_sum> initF(n);
    for(int i=0;i<n;i++) initF[i] = {a[i], 1};
    atcoder::lazy_segtree<S_assign_sum, op_assign_sum, e_assign_sum, F_assign_sum, mapping_assign_sum, composition_assign_sum, id_assign_sum> lzF(initF);
    lzF.apply(2,7, 2); // set [2,7) to 2
    cout << "assign+sum total: " << lzF.prod(0,n).value << endl;


    return 0;
}

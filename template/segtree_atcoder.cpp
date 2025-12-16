#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

/*
  segtree_atcoder.cpp — 簡潔な備忘録（コピペ用）

  目的: ACL の `segtree` / `lazy_segtree` を問題で使うときに
  最低限コピペすれば動くテンプレを短くまとめる。

  収録 (短い順):
   - segtree: max / min / sum
   - lazy assign: max / min / sum (assign = 区間一括更新)
   - lazy add: min + add (区間加算)
   - pair<int,int> を要素にする例と lambda トリック
*/

// -------------------------
// 1) segtree (max/min/sum)
// -------------------------
long long op_max(long long a, long long b){ return max(a,b); }
long long e_max(){ return LLONG_MIN/4; }
long long op_min(long long a, long long b){ return min(a,b); }
long long e_min(){ return LLONG_MAX/4; }
long long op_sum(long long a, long long b){ return a + b; }
long long e_sum(){ return 0; }

// -------------------------
// 2) lazy add (min + add) -- range add, range min query
//    （F = add amount）
// -------------------------
long long op_min_add(long long a, long long b){ return min(a,b); }
long long e_min_add(){ return LLONG_MAX/4; }
long long mapping_add(long long f, long long x){ return x + f; }
long long composition_add(long long f_new, long long f_old){ return f_new + f_old; }
long long id_add(){ return 0; }

// -------------------------
// 3) lazy assign の共通: assign 用の no-op 定義
//    F = assign value; ASSIGN_NOOP を使うと "何もしない"
// -------------------------
const long long ASSIGN_NOOP = LLONG_MIN/8;

// 3-a) lazy assign (max) -- S = long long, F = assign value
long long op_assign_max(long long a, long long b){ return max(a,b); }
long long e_assign_max(){ return LLONG_MIN/4; }
long long mapping_assign_max(long long f, long long x){ return (f==ASSIGN_NOOP) ? x : f; }
long long composition_assign_max(long long f_new, long long f_old){ return (f_new==ASSIGN_NOOP) ? f_old : f_new; }
long long id_assign_max(){ return ASSIGN_NOOP; }

// 3-b) lazy assign (min)
long long op_assign_min(long long a, long long b){ return min(a,b); }
long long e_assign_min(){ return LLONG_MAX/4; }
long long mapping_assign_min(long long f, long long x){ return (f==ASSIGN_NOOP) ? x : f; }
long long composition_assign_min(long long f_new, long long f_old){ return (f_new==ASSIGN_NOOP) ? f_old : f_new; }
long long id_assign_min(){ return ASSIGN_NOOP; }

// 3-c) lazy assign (sum) -- S に (sum, len)
struct SegSum { long long sum; int len; };
SegSum op_assign_sum(SegSum a, SegSum b){ return {a.sum + b.sum, a.len + b.len}; }
SegSum e_assign_sum(){ return {0,0}; }
SegSum mapping_assign_sum(long long f, SegSum x){ return (f==ASSIGN_NOOP) ? x : SegSum{ f * x.len, x.len }; }
long long composition_assign_sum(long long f_new, long long f_old){ return (f_new==ASSIGN_NOOP) ? f_old : f_new; }
long long id_assign_sum(){ return ASSIGN_NOOP; }

// -------------------------
// 4) pair<int,int> の例 と "lambda を使う" トリック
// -------------------------
// 例: (value, index) のペアを保持して value の最大値を返す (同値なら小さい index)
pair<int,int> op_pair_max(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first) return (a.first > b.first) ? a : b;
    return (a.second < b.second) ? a : b;
}
pair<int,int> e_pair_max(){ return {INT_MIN/4, INT_MAX/4}; }

// lambda を使いたい場合のトリック: ラムダ本体を static なオブジェクトに格納し、
// グローバル関数を作ってそれを呼ぶ。テンプレートにはグローバル関数を渡す。
static const auto op_pair_lambda = [](pair<int,int> a, pair<int,int> b){
    if(a.first != b.first) return (a.first > b.first) ? a : b;
    return (a.second < b.second) ? a : b;
};
pair<int,int> op_pair_forward(pair<int,int> a, pair<int,int> b){ return op_pair_lambda(a,b); }
pair<int,int> e_pair_forward(){ return {INT_MIN/4, INT_MAX/4}; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a={3,1,4,1,5,9,2};
    int n=(int)a.size();

    // segtree: max/min/sum
    segtree<long long, op_max, e_max> segMax(n);
    segtree<long long, op_min, e_min> segMin(n);
    segtree<long long, op_sum, e_sum> segSum(n);
    for(int i=0;i<n;i++){ segMax.set(i,a[i]); segMin.set(i,a[i]); segSum.set(i,a[i]); }

    cout << "segtree max [1,5): " << segMax.prod(1,5) << endl;
    cout << "segtree min [0,7): " << segMin.prod(0,7) << endl;
    cout << "segtree sum [2,6): " << segSum.prod(2,6) << endl;

    // pair<int,int> を要素とする segtree
    segtree<pair<int,int>, op_pair_max, e_pair_max> segPair(n);
    for(int i=0;i<n;i++) segPair.set(i, { (int)a[i], i });
    auto p = segPair.prod(0,n);
    cout << "pair max (value,index): (" << p.first << "," << p.second << ")\n";

    // lambda-forward を使った segtree（テンプレートには関数名を渡す）
    segtree<pair<int,int>, op_pair_forward, e_pair_forward> segPair2(n);
    for(int i=0;i<n;i++) segPair2.set(i, { (int)a[i], i });
    auto p2 = segPair2.prod(0,n);
    cout << "pair max (via lambda-forward): (" << p2.first << "," << p2.second << ")\n";

    // lazy assign (max)
    lazy_segtree<long long, op_assign_max, e_assign_max, long long, mapping_assign_max, composition_assign_max, id_assign_max> lzMax(n);
    for(int i=0;i<n;i++) lzMax.set(i,a[i]);
    lzMax.apply(2,5, 10); // [2,5) を 10 に上書き
    cout << "lazy assign max prod(0,7): " << lzMax.prod(0,7) << endl;

    // lazy assign (min)
    lazy_segtree<long long, op_assign_min, e_assign_min, long long, mapping_assign_min, composition_assign_min, id_assign_min> lzMin(n);
    for(int i=0;i<n;i++) lzMin.set(i,a[i]);
    lzMin.apply(0,3, 0); // [0,3) を 0 に上書き
    cout << "lazy assign min prod(0,7): " << lzMin.prod(0,7) << endl;

    // lazy assign (sum)
    lazy_segtree<SegSum, op_assign_sum, e_assign_sum, long long, mapping_assign_sum, composition_assign_sum, id_assign_sum> lzSum(n);
    for(int i=0;i<n;i++) lzSum.set(i, SegSum{a[i],1});
    lzSum.apply(3,7, 2); // [3,7) を 2 に上書き
    cout << "lazy assign sum total: " << lzSum.prod(0,n).sum << endl;

    // lazy add (min + add)
    lazy_segtree<long long, op_min_add, e_min_add, long long, mapping_add, composition_add, id_add> lzAdd(n);
    for(int i=0;i<n;i++) lzAdd.set(i,a[i]);
    lzAdd.apply(0,3, 5); // +5 to [0,3)
    cout << "lazy add min [0,3): " << lzAdd.prod(0,3) << endl;


    return 0;
}

// https://atcoder.jp/contests/abc326/tasks/abc326_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


// 与えられた配列 a の各要素に "+" または "-" を割り当てて合計 target を作れるかを判定する。
// 戻り値: 可能なら true。out に各要素が 0:+ / 1:- の順で格納される（out.size()==a.size()）。
// アルゴリズム: meet-in-the-middle を高速に行うために次を用いる。
//  - 配列を左右に分割し、それぞれの半分についてすべての符号割当（部分集合）を列挙する。
//  - 各マスクの合計は lowbit DP を使って O(1) 更新で計算する（mask と mask^low の結果から導出）。
//  - 左側の各合計 s に対して右側で target - s を二分探索で探し、見つかればマスクを結合して out を作る。
// lowbit DP による合計計算はメモリ局所性が良く非常に速いため、2^{n/2} 程度の列挙が現実的に行えます。
bool find_signed_assignment(const vi &a, int target, v<bool> &out){
    int n=a.size();
    if(n==0) return target==0;

    // 左右に分割する (左: [0,h), 右: [h,n) )
    int h = n/2;
    int h2 = n-h;

    // --- 左側の全列挙 ---
    int L = 1<<h;
    vi sumNegL(L);
    // mask を 1 から順に作り、lowbit を使って 1 ビット分だけ足し合わせる
    for(int mask=1; mask<L; ++mask){
        int low = mask & -mask;
        int pos = __builtin_ctz(low);
        sumNegL[mask] = sumNegL[mask ^ low] + a[pos];
    }
    // totalL は左側の全要素和。ここから sum = totalL - 2*sumNeg を計算すると
    // ビットが 1 の要素は負、0 の要素は正としての合計が得られる。
    int totalL=0;
    for(int i=0;i<h;++i) totalL += a[i];
    v<pii> left; left.reserve(L);
    for(int mask=0; mask<L; ++mask){
        int s = totalL - 2*sumNegL[mask];
        left.emplace_back(s,mask);
    }

    // --- 右側の全列挙 ---
    int R = 1<<h2;
    v<int> sumNegR(R);
    for(int mask=1; mask<R; ++mask){
        int low = mask & -mask;
        int pos = __builtin_ctz(low);
        sumNegR[mask] = sumNegR[mask ^ low] + a[h + pos];
    }
    int totalR=0;
    for(int i=0;i<h2;++i) totalR += a[h+i];
    v<pii> right; right.reserve(R);
    for(int mask=0; mask<R; ++mask){
        int s = totalR - 2*sumNegR[mask];
        right.emplace_back(s,mask);
    }

    // 右側を合計でソートしておき、左側の各合計に対して二分探索で補集合を探す
    sort(right.begin(), right.end(), [](const pii&A,const pii&B){ return A.first < B.first; });

    // left の各 (sum,mask) に対して、need = target - sum を右で探す
    for(auto&p:left){
        int need = target - p.first;
        auto it = lower_bound(right.begin(), right.end(), need, [](const pii&A, const int &v){ return A.first < v; });
        if(it != right.end() && it->first == need){
            out.clear(); out.reserve(n);
            int mL = p.second;
            int mR = it->second;
            for(int i=0;i<h;++i) out.pb((mL>>i)&1);
            for(int i=0;i<h2;++i) out.pb((mR>>i)&1);
            return true;
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,y;
    cin >> n >> x >> y;
    vi xx,yy;
    rep(i,n) {
        int a;
        cin >> a;
        if (i&1) xx.pb(a);
        else yy.pb(a);
    }
    int xs=xx.size(),ys=yy.size();
    v<bool> vx;
    if(!find_signed_assignment(xx, x, vx)){
        YesNo(0);
        return 0;
    }

    v<bool> vy;
    if(!find_signed_assignment(yy, y, vy)){
        YesNo(0);
        return 0;
    }

    bool last=0;
    string ans="";
    rep(i,xs) {
        ans.pb(last==vy[i]?'L':'R');
        last=vy[i];
        ans.pb(last!=vx[i]?'L':'R');
        last=vx[i];
    }
    if (ys>xs) {
        ans.pb(last==vy[ys-1]?'L':'R');
    }
    YesNo(1);
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc442/tasks/abc442_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

using S=int;
S op(S a,S b){return min(a,b);}
S e(){return INF;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // dp[j]:jマス塗った状態での塗り替え最小値
    segtree<S,op,e> dp(n+1);
    dp.set(n,0);
    rep(i,n) {
        string s;
        cin >> s;
        vi sm(n+1,0);
        rep(j,n) sm[j+1]=sm[j]+(s[j]=='#');
        v<S> init(n+1);
        rep(j,n+1) init[j]=dp.prod(j,n+1)+sm[j]+((n-j)-(sm[n]-sm[j]));
        dp=segtree<S,op,e>(init);
    }
    print(dp.all_prod());

    return 0;
}

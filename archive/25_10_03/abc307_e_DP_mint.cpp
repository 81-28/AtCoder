// https://atcoder.jp/contests/abc307/tasks/abc307_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using mint=modint998244353;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // dp[i][j]:i番目までで、j(0番目と同じである)の時のパターン数
    v<v<mint>> dp(n,v<mint>(2));
    dp[0]={0,m};
    for (int i=1; i<n; ++i) dp[i]={dp[i-1][0]*(m-2)+dp[i-1][1]*(m-1),dp[i-1][0]};
    print(dp[n-1][0].val());

    return 0;
}

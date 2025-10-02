// https://atcoder.jp/contests/abc310/tasks/abc310_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    v<bool> b(n);
    rep(i,n) b[i]=s[i]-'0';
    // dp[i][j]:i番までで、jとなるものの個数
    vvi dp(n,vi(2,0));
    dp[0][b[0]]=1;
    int ans=dp[0][1];
    for (int i=1; i<n; ++i) {
        dp[i][b[i]]=1;
        if (b[i]) {
            dp[i][0]+=dp[i-1][1];
            dp[i][1]+=dp[i-1][0];
        } else {
            dp[i][1]+=dp[i-1][0]+dp[i-1][1];
        }
        ans+=dp[i][1];
    }
    print(ans);

    return 0;
}

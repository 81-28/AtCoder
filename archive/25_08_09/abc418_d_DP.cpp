// https://atcoder.jp/contests/abc418/tasks/abc418_d

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
    string t;
    cin >> n >> t;
    // dp[i][j]:iまででjとなる個数
    vvi dp(n,vi(2,0));
    int ans=0;
    rep(i,n) {
        bool b=t[i]-'0';
        if (i) {
            dp[i][1]+=dp[i-1][b];
            dp[i][0]+=dp[i-1][!b];
        }
        ++dp[i][b];
        ans+=dp[i][1];
    }
    print(ans);

    return 0;
}

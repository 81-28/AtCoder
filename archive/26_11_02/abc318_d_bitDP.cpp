// https://atcoder.jp/contests/abc318/tasks/abc318_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi d(n,vi(n,0));
    rep(i,n-1)for(int j=i+1; j<n; ++j) cin >> d[i][j];
    int mx=1<<n;
    // dp[i]:iの立っているビットの位置を選んだ時の最大スコア
    vi dp(mx,0);
    rep(i,mx-1) {
        int x=-1;
        rep(j,n) {
            if ((i>>j)&1) continue;
            x=j;
            break;
        }
        rep(y,n) {
            if ((i>>y)&1) continue;
            int nxt=i|(1<<x)|(1<<y);
            chmax(dp[nxt],dp[i]+d[x][y]);
        }
    }
    print(dp[mx-1]);


    return 0;
}

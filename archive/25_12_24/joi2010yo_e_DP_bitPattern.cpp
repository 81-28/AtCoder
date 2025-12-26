// https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    int m=1e5;
    // dp[i][j][k]:位置ijで、状態k(k[0]:曲がるかどうか,k[1]:東かどうか)のパターン
    v<vvi> dp(h,vvi(w,vi(4,0)));
    rep1(i,h-1) dp[i][0][0]=1;
    rep1(j,w-1) dp[0][j][2]=1;
    rep1(i,h-1)rep1(j,w-1) {
        dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1];
        dp[i][j][1]+=dp[i-1][j][2];
        dp[i][j][2]+=dp[i][j-1][2]+dp[i][j-1][3];
        dp[i][j][3]+=dp[i][j-1][0];
        rep(k,4) dp[i][j][k]%=m;
    }
    int ans=0;
    rep(k,4) ans+=dp[h-1][w-1][k];
    print(ans%m);

    return 0;
}

// https://atcoder.jp/contests/abc180/tasks/abc180_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<tuple<int,int,int>> t(n);
    for (auto&[x,y,z]:t) cin >> x >> y >> z;
    // cost[i][j]:iからjに向かうのにかかるコスト
    vvi cost(n,vi(n));
    rep(i,n) {
        const auto&[a,b,c]=t[i];
        rep(j,n) {
            const auto&[p,q,r]=t[j];
            cost[i][j]=abs(p-a)+abs(q-b)+max(r-c,0LL);
        }
    }
    constexpr int inf=INT_MAX;
    // dp[i][j]:頂点iにいて、訪問状態jになる最小コスト
    // (j>>k)&1:頂点kが訪問済みかどうか
    vvi dp(n,vi(1<<n,inf));
    // 頂点0を訪問済みにしても、最終的に全部回った状態しか見ないので問題無し
    // パターンが減る分、速くなる
    dp[0][1]=0;
    // 状態iで、jからkへ向かう
    // 状態iになるには、i未満から向かう方法しか無い為、状態iに来る全パターンは探索済み
    rep(i,1<<n)rep(j,n)rep(k,n) {
        // 条件無い方が高速
        // if (!((i>>j)&1)) continue;
        // 頂点kの条件が無いのは、2度訪れても良いから(頂点0に戻る為)
        chmin(dp[k][i|(1<<k)],dp[j][i]+cost[j][k]);
    }
    print(dp[0][(1<<n)-1]);

    return 0;
}

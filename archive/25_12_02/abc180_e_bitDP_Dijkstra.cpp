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
    constexpr int inf=LLONG_MAX;
    // dp[i][j]:頂点iにいて、訪問状態jになる最小コスト
    // (j>>k)&1:頂点kが訪問済みかどうか
    vvi dp(n,vi(1<<n,inf));
    // {コスト,頂点,訪問状態}
    priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>> pq;
    // 頂点0に戻るので、最初は未訪問にする
    dp[0][0]=0;
    pq.push({0,0,0});
    while (!pq.empty()) {
        auto[c,pos,trail]=pq.top();
        pq.pop();
        rep(i,n) {
            if (!((trail>>i)&1)) {
                int nxt=trail|(1<<i);
                if (chmin(dp[i][nxt],c+cost[pos][i])) pq.push({dp[i][nxt],i,nxt});
            }
        }
    }
    print(dp[0][(1<<n)-1]);

    return 0;
}

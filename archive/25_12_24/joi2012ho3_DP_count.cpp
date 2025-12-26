// https://atcoder.jp/contests/joi2012ho/tasks/joi2012ho3

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t,s;
    cin >> n >> t >> s;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    // dp[i][j]:iまでのいくつかの夜店で遊んだ状態で、時刻jにおける最大楽しさ
    vvi dp(n+1,vi(t+1,0));
    rep1(i,n) {
        dp[i]=dp[i-1];
        auto[a,b]=p[i-1];
        rep1(j,s) {
            chmax(dp[i][j],dp[i][j-1]);
            int k=j-b;
            if (k<0) continue;
            chmax(dp[i][j],dp[i-1][k]+a);
        }
        // チェックポイントは飛び越えず確実に通る
        for (int j=s+1; j<=t; ++j) {
            chmax(dp[i][j],dp[i][j-1]);
            int k=j-b;
            if (k<s) continue;
            chmax(dp[i][j],dp[i-1][k]+a);
        }
    }
    print(dp[n][t]);

    return 0;
}

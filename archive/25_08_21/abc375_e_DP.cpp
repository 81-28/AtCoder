// https://atcoder.jp/contests/abc375/tasks/abc375_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0;
    v<pii> p(n);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        sm+=b;
    }
    if (sm%3) {
        print(-1);
        return 0;
    }
    sm/=3;
    ++sm;
    int inf=INT_MAX/2;
    // dp[i][j]:今までで、チームの強さが{1:i,2:j,3:残り}となる最小変更数
    vvi dp(sm,vi(sm,inf));
    dp[0][0]=0;
    for (auto[a,b]:p) {
        vvi d(sm,vi(sm,inf));
        rep(i,sm)rep(j,sm) {
            if (i-b>=0) chmin(d[i][j],dp[i-b][j]+(a!=1));
            if (j-b>=0) chmin(d[i][j],dp[i][j-b]+(a!=2));
            chmin(d[i][j],dp[i][j]+(a!=3));
        }
        dp=d;
    }
    --sm;
    print(dp[sm][sm]==inf?-1:dp[sm][sm]);

    return 0;
}

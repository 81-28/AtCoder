// https://atcoder.jp/contests/abc410/tasks/abc410_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<class T> constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,h,m;
    cin >> n >> h >> m;
    // dp[i][j]:i対目で体力jにおけるm最大値
    vvi dp(n+1,vi(h+1,-1));
    dp[0][h]=m;
    rep1(i,n) {
        pii p;
        cin >> p;
        bool ok=0;
        rep(j,h+1) {
            if (chmax(dp[i][j],dp[i-1][j]-p.s)) ok=1;
            if (j+p.f<=h && chmax(dp[i][j],dp[i-1][j+p.f])) ok=1;
        }
        if (!ok) {
            print(i-1);
            return 0;
        }
    }
    print(n);

    return 0;
}

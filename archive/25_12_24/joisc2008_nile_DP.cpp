// https://atcoder.jp/contests/joisc2008/tasks/joisc2008_nile

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    vvi p(d,vi(n));
    cin >> p;
    // dp[i][j]:店舗iでj+1日連続で購入した場合の最小金額
    vvi dp(n,vi(3,INF));
    // 現在の最小値
    int ans=0;
    rep(i,d) {
        vvi dpp(n,vi(3,INF));
        int mi=INF;
        rep(j,n) {
            dpp[j][0]=ans+p[i][j];
            chmin(dpp[j][1],dp[j][0]+p[i][j]*9/10);
            chmin(dpp[j][2],min(dp[j][1],dp[j][2])+p[i][j]*7/10);
            chmin(mi,min(dpp[j]));
        }
        dp=dpp;
        ans=mi;
    }
    print(ans);

    return 0;
}

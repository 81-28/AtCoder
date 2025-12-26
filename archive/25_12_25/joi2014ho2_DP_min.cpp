// https://atcoder.jp/contests/joi2014ho/tasks/joi2014ho2

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m,n;
    cin >> m >> n;
    vi p(m);
    v<pii> q(n);
    cin >> p;
    rep(i,n) cin >> q[i];
    sort(rall(p));
    vi sm=p;
    
    rep1(i,m-1) sm[i]+=sm[i-1];
    // dp[i]:i個の饅頭を売る時の箱の合計価格の最小値
    vi dp(m+1,INF);
    dp[0]=0;
    int ans=0;
    rep(i,n) {
        auto[cnt,cost]=q[i];
        // 下の実装で不足する、(m-cnt,m] -> m(遷移後固定) の遷移を埋める
        rep(k,cnt) {
            if (m-k<0) break;
            chmin(dp[m],dp[m-k]+cost);
        }
        for (int j=m; j>0; --j) {
            // 箱を使わない(下との組み合わせで、実質、箱に最大数入れない遷移)
            if (j<m) chmin(dp[j],dp[j+1]);
            // 箱iを使って箱に入れられる個数(最大数固定)少ない状態から遷移
            if (j-cnt>=0) chmin(dp[j],dp[j-cnt]+cost);
        }
    }
    rep1(i,m) chmax(ans,sm[i-1]-dp[i]);
    print(ans);

    return 0;
}

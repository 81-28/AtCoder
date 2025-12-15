// https://atcoder.jp/contests/abc358/tasks/abc358_g

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    pii st;
    cin >> h >> w >> k >> st;
    --st;
    vvi a(h,vi(w));
    cin >> a;
    // 遠回りが最適な可能性もあり
    // 相異なるマスを通ることを考え、そのパスに含まれる最大に留まれば良いので、高々h*w回の移動のみ考慮すれば良い
    int mv=min(k,h*w);
    // dp[m][i][j]:m+1回動いた後の、位置ijの楽しさの最大値
    v<vvi> dp(mv,vvi(h,vi(w,0)));
    dp[0][st.f][st.s]=a[st.f][st.s];
    rep(l,4) {
        auto[x,y]=st+dir[l];
        if (OutOfGrid({x,y},{h,w})) continue;
        dp[0][x][y]=a[x][y];
    }
    rep1(m,mv-1) {
        rep(i,h)rep(j,w) {
            if (dp[m-1][i][j]==0) continue;
            chmax(dp[m][i][j],dp[m-1][i][j]+a[i][j]);
            rep(l,4) {
                auto[x,y]=pii(i,j)+dir[l];
                if (OutOfGrid({x,y},{h,w})) continue;
                chmax(dp[m][x][y],dp[m-1][i][j]+a[x][y]);
            }
        }
    }
    int ans=0;
    rep(i,h)rep(j,w) chmax(ans,dp[mv-1][i][j]+a[i][j]*(k-mv));
    print(ans);

    return 0;
}

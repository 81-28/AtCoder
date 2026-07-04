// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder;

using ll=long long;
#define int ll
using ull=unsigned long long;
using ld=long double;
constexpr int INF=numeric_limits<int>::max()/4;
const ld PI=acos(-1);
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
// const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
inline int ManhattanDist(const pii& a,const pii& b){return abs(a.first-b.first)+abs(a.second-b.second);}
// using mint=modint998244353;
// using mint=modint1000000007;
// using mint=modint;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

// `double pow()`では大きい数の時に誤差が発生する オーバーフローに注意 剰余のときは`modint.pow()`で良い
int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}
// log(0)=-1
int int_log2(int n) {
    int i=-1;
    for(;n>0;n>>=1)++i;
    return i;
}
// `double log10()`も同様に誤差が発生するので、`to_string(n).size()`が良い

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairのデクリメント
// template<typename F,typename S>
// pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}
// // pairと定数の掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const pair<F,S>& p,const T& a){return{p.f*a,p.s*a};}
// // 定数とpairの掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const T& a,const pair<F,S>& p){return{a*p.f,a*p.s};}

// AtCoderでは、inもoutもvector,pair,tuple組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename... Args>
ostream &operator<<(ostream &os,const tuple<Args...> &t){apply([&os](const auto&... args){int i=0;((os<<(i++?" ":"")<<args),...);},t);return os;}
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}

// 区間のクエリが必要ならセグ木使う
// 値の範囲が大きい→座標圧縮で解けないかを考える

# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")


struct G{
    int u,d,l,r;
    G(int a,int b,int c,int e) {
        u=a,d=b,l=c,r=e;
    }
    G() {
        u=d=l=r=0;
    }
};
struct F{
    int ul,dl,ur,dr;
    F(int a,int b,int c,int d) {
        ul=a,dl=b,ur=c,dr=d;
    }
    F() {
        ul=dl=ur=dr=INF;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    for(;;) {
        int n,U,V;
        cin >> n >> U >> V;
        if(!n) return 0;
        int m;
        cin >> m;
        vi row={0,n},col={0,n};
        v<tuple<int,int,int,int>> e(m);
        for (auto&[a,b,c,d]:e) {
            cin >> a >> b >> c >> d;
            row.pb(a-1);
            row.pb(b);
            col.pb(c-1);
            col.pb(d);
        }
        sort(all(row)),sort(all(col));
        uniq(row),uniq(col);
        int h=row.size(),w=col.size();

        // ブロックの{上,下,左,右}
        vector g(h-1,v<G>(w-1));
        rep(i,h-1)rep(j,w-1) {
            g[i][j]=G(row[i]+1,row[i+1],col[j]+1,col[j+1]);
        }

        vvb wall(h-1,vb(w-1,0));
        for (auto[a,b,c,d]:e) {
            auto itxu=lower_bound(all(row),a-1);
            int xu=itxu-row.begin();
            auto itxd=lower_bound(all(row),b);
            int xd=itxd-row.begin();

            auto ityl=lower_bound(all(col),c-1);
            int yl=ityl-col.begin();
            auto ityr=lower_bound(all(col),d);
            int yr=ityr-col.begin();

            for (int i=xu; i<xd; i++) {
                for (int j=yl; j<yr; j++) {
                    wall[i][j]=1;
                }
            }
            // print(xu,xd,yl,yr);
        }
        // rep(i,h-1) print(wall[i]);

        auto itr=lower_bound(all(row),U);
        int xx=itr-row.begin()-1;
        auto itc=lower_bound(all(col),V);
        int yy=itc-col.begin()-1;
        // ブロックの{左上,左下,右上,右下}それぞれの位置の最短
        vector ans(h-1,v<F>(w-1));
        ans[xx][yy].ul = U-g[xx][yy].u + V-g[xx][yy].l;
        ans[xx][yy].dl = g[xx][yy].d-U + V-g[xx][yy].l;
        ans[xx][yy].ur = U-g[xx][yy].u + g[xx][yy].r-V;
        ans[xx][yy].dr = g[xx][yy].d-U + g[xx][yy].r-V;
        // queue<pii> qu;
        // {ブロックの最小距離,i,j}
        priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>> pq;
        // vvb done(h-1,vb(w-1,0));
        // qu.push({xx,yy});
        // done[xx][yy]=1;
        vvi dist(h-1,vi(w-1,INF));
        dist[xx][yy]=min({ans[xx][yy].ul,ans[xx][yy].dl,ans[xx][yy].dl,ans[xx][yy].dr});
        pq.push({dist[xx][yy],xx,yy});
        // while (!qu.empty()) {
        while (!pq.empty()) {
            // pii pos=qu.front();
            // pii pos=pq.front();
            // auto[nx,ny]=pos;
            auto [nd,nx,ny]=pq.top();
            // qu.pop();
            pq.pop();
            if (dist[nx][ny]<nd) continue;
            pii pos={nx,ny};
            rep(k,4) {
                auto[x,y]=pos+dir[k];
                if (OutOfGrid({x,y},{h-1,w-1})) continue;
                if (wall[x][y]) continue;
                // if (done[x][y]) continue;
                // done[x][y]=1;
                // print(x,y);
                int nxd=INF;
                chmin(ans[x][y].ul, ans[nx][ny].ul + ManhattanDist({g[nx][ny].u,g[nx][ny].l},{g[x][y].u,g[x][y].l}));
                chmin(ans[x][y].ul, ans[nx][ny].dl + ManhattanDist({g[nx][ny].d,g[nx][ny].l},{g[x][y].u,g[x][y].l}));
                chmin(ans[x][y].ul, ans[nx][ny].ur + ManhattanDist({g[nx][ny].u,g[nx][ny].r},{g[x][y].u,g[x][y].l}));
                chmin(ans[x][y].ul, ans[nx][ny].dr + ManhattanDist({g[nx][ny].d,g[nx][ny].r},{g[x][y].u,g[x][y].l}));
                chmin(nxd,ans[x][y].ul);

                chmin(ans[x][y].dl, ans[nx][ny].ul + ManhattanDist({g[nx][ny].u,g[nx][ny].l},{g[x][y].d,g[x][y].l}));
                chmin(ans[x][y].dl, ans[nx][ny].dl + ManhattanDist({g[nx][ny].d,g[nx][ny].l},{g[x][y].d,g[x][y].l}));
                chmin(ans[x][y].dl, ans[nx][ny].ur + ManhattanDist({g[nx][ny].u,g[nx][ny].r},{g[x][y].d,g[x][y].l}));
                chmin(ans[x][y].dl, ans[nx][ny].dr + ManhattanDist({g[nx][ny].d,g[nx][ny].r},{g[x][y].d,g[x][y].l}));
                chmin(nxd,ans[x][y].dl);

                chmin(ans[x][y].ur, ans[nx][ny].ul + ManhattanDist({g[nx][ny].u,g[nx][ny].l},{g[x][y].u,g[x][y].r}));
                chmin(ans[x][y].ur, ans[nx][ny].dl + ManhattanDist({g[nx][ny].d,g[nx][ny].l},{g[x][y].u,g[x][y].r}));
                chmin(ans[x][y].ur, ans[nx][ny].ur + ManhattanDist({g[nx][ny].u,g[nx][ny].r},{g[x][y].u,g[x][y].r}));
                chmin(ans[x][y].ur, ans[nx][ny].dr + ManhattanDist({g[nx][ny].d,g[nx][ny].r},{g[x][y].u,g[x][y].r}));
                chmin(nxd,ans[x][y].ur);

                chmin(ans[x][y].dr, ans[nx][ny].ul + ManhattanDist({g[nx][ny].u,g[nx][ny].l},{g[x][y].d,g[x][y].r}));
                chmin(ans[x][y].dr, ans[nx][ny].dl + ManhattanDist({g[nx][ny].d,g[nx][ny].l},{g[x][y].d,g[x][y].r}));
                chmin(ans[x][y].dr, ans[nx][ny].ur + ManhattanDist({g[nx][ny].u,g[nx][ny].r},{g[x][y].d,g[x][y].r}));
                chmin(ans[x][y].dr, ans[nx][ny].dr + ManhattanDist({g[nx][ny].d,g[nx][ny].r},{g[x][y].d,g[x][y].r}));
                chmin(nxd,ans[x][y].dr);

                if (chmin(dist[x][y],nxd)) pq.push({dist[x][y],x,y});
                // qu.push({x,y});

                // print(x,y);
                // print(ans[x][y].ul);
                // print(ans[x][y].dl);
                // print(ans[x][y].ur);
                // print(ans[x][y].dr);
            }
        }


        int q;
        cin >> q;
        while (q--) {
            int x,y;
            cin >> x >> y;
            auto itx=lower_bound(all(row),x);
            int ix=itx-row.begin()-1;
            auto ity=lower_bound(all(col),y);
            int jy=ity-col.begin()-1;
            if (ix==xx && jy==yy) {
                print(ManhattanDist({x,y},{U,V}));
                continue;
            }
            int res=INF;
            chmin(res, ans[ix][jy].ul + ManhattanDist({x,y},{g[ix][jy].u,g[ix][jy].l}));
            chmin(res, ans[ix][jy].dl + ManhattanDist({x,y},{g[ix][jy].d,g[ix][jy].l}));
            chmin(res, ans[ix][jy].ur + ManhattanDist({x,y},{g[ix][jy].u,g[ix][jy].r}));
            chmin(res, ans[ix][jy].dr + ManhattanDist({x,y},{g[ix][jy].d,g[ix][jy].r}));
            if (res==INF) print("no");
            else print(res);
        }
        // print();
    }


    return 0;
}

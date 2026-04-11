// https://atcoder.jp/contests/abc453/tasks/abc453_d

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S> pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairの加算代入 (+=)
template<typename F,typename S> pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> g(h);
    cin >> g;
    pii st,go;
    rep(i,h)rep(j,w) {
        if (g[i][j]=='S') st={i,j};
        if (g[i][j]=='G') go={i,j};
    }
    // d[i][j][k]:位置ijで方向kで最短距離
    v<vvi> d(h,vvi(w,vi(4,INF)));
    // {距離,位置,方向}
    priority_queue<tuple<int,pii,int>,v<tuple<int,pii,int>>,greater<>> q;
    rep(i,4) {
        d[st.f][st.s][i]=0;
        q.push({0,st,i});
    }
    while (!q.empty()) {
        auto[dn,pos,di]=q.top();
        auto[x,y]=pos;
        q.pop();
        rep(i,4) {
            if (g[x][y]=='o' && i!=di) continue;
            if (g[x][y]=='x' && i==di) continue;
            auto[nx,ny]=pos+dir[i];
            if (OutOfGrid({nx,ny},{h,w})) continue;
            if (g[nx][ny]=='#') continue;
            if (chmin(d[nx][ny][i],dn+1)) q.push({d[nx][ny][i],{nx,ny},i});
        }
    }
    rep(i,4) {
        string ans="";
        if (d[go.f][go.s][i]!=INF) {
            YesNo(1);
            pii pos=go;
            int di=i;
            while (pos!=st) {
                if (di==0) ans.pb('U');
                if (di==1) ans.pb('L');
                if (di==2) ans.pb('D');
                if (di==3) ans.pb('R');
                auto[x,y]=pos;
                auto[nx,ny]=pos+dir[(di+2)%4];
                rep(j,4) {
                    if (d[nx][ny][j]!=d[x][y][di]-1) continue;
                    if (g[nx][ny]=='o' && j!=di) continue;
                    if (g[nx][ny]=='x' && j==di) continue;
                    di=j;
                    pos={nx,ny};
                    break;
                }
            }
            int len=ans.size();
            for (int j=len-1; j>=0; --j) cout<<ans[j];
            print();
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

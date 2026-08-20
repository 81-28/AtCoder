// https://atcoder.jp/contests/abc184/tasks/abc184_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int h,w;
    cin >> h >> w;
    v<string> a(h);
    cin >> a;
    pii st,go;
    v<v<pii>> c(26);
    rep(i,h)rep(j,w) {
        if (a[i][j]=='S') st={i,j};
        if (a[i][j]=='G') go={i,j};
        if ('a'<=a[i][j] && a[i][j]<='z') c[a[i][j]-'a'].pb({i,j});
    }
    vvi d(h,vi(w,h*w));
    // {距離,位置}
    priority_queue<pair<int,pii>,v<pair<int,pii>>,greater<>> q;
    d[st.f][st.s]=0;
    q.push({d[st.f][st.s],st});
    vb b(26,0);
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        auto[x,y]=pos;
        if (dist>d[x][y]) continue;
        rep(k,4) {
            auto[nx,ny]=pos+dir[k];
            if (OutOfGrid({nx,ny},{h,w})) continue;
            if (a[nx][ny]=='#') continue;
            if (chmin(d[nx][ny],dist+1)) q.push({d[nx][ny],{nx,ny}});
        }
        if ('a'<=a[x][y] && a[x][y]<='z') {
            int ch=a[x][y]-'a';
            if (b[ch]) continue;
            b[ch]=1;
            for (auto[nx,ny]:c[ch]) {
                if (chmin(d[nx][ny],dist+1)) q.push({d[nx][ny],{nx,ny}});
            }
        }
    }
    int ans=d[go.f][go.s];
    print(ans==h*w?-1:ans);

    return 0;
}

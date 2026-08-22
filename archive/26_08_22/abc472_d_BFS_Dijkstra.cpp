// https://atcoder.jp/contests/abc472/tasks/abc472_d

#include<bits/stdc++.h>
using namespace std;

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
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    cin >> h >> w >> k;
    v<string> st(h);
    cin >> st;
    vi r(h,0),c(w,0);
    rep(i,h)rep(j,w) {
        if (st[i][j]=='.') continue;
        ++r[i],++c[j];
    }
    vvi d(h,vi(w,h*w));
    // {距離,位置}
    priority_queue<pair<int,pii>,v<pair<int,pii>>,greater<>> q;
    rep(i,h)rep(j,w) {
        if (r[i] || c[j]) continue;
        d[i][j]=0;
        q.push({0,{i,j}});
    }
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        auto[x,y]=pos;
        if (dist>d[x][y]) continue;
        rep(k,4) {
            auto[nx,ny]=pos+dir[k];
            if (OutOfGrid({nx,ny},{h,w})) continue;
            if (st[nx][ny]=='#') continue;
            if (chmin(d[nx][ny],dist+1)) q.push({d[nx][ny],{nx,ny}});
        }
    }
    int ans=0;
    rep(i,h)rep(j,w) ans+=d[i][j]<=k;
    print(ans);

    return 0;
}

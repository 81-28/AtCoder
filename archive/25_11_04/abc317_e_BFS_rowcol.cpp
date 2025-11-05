// https://atcoder.jp/contests/abc317/tasks/abc317_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
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
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


constexpr int inf=INT_MAX;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<char,bool> wall;
    wall['.']=0;
    wall['#']=1;
    wall['>']=1;
    wall['v']=1;
    wall['<']=1;
    wall['^']=1;
    wall['S']=0;
    wall['G']=0;

    int h,w;
    cin >> h >> w;
    v<string> a(h);
    cin >> a;
    v<string> row(h,"#"),col(w,"#");
    rep(i,h) {
        rep(j,w) {
            if (wall[a[i][j]]) row[i].pb(a[i][j]);
        }
        row[i].pb('#');
    }
    rep(j,w) {
        rep(i,h) {
            if (wall[a[i][j]]) col[j].pb(a[i][j]);
        }
        col[j].pb('#');
    }
    vi x(w,0),y(h,0);
    v<v<bool>> b(h,v<bool>(w,0));
    pii st,go;
    rep(i,h)rep(j,w) {
        if (a[i][j]=='S') st={i,j};
        if (a[i][j]=='G') go={i,j};
        if (wall[a[i][j]]) {
            b[i][j]=1;
            ++x[j],++y[i];
        } else {
            char u=col[j][x[j]],d=col[j][x[j]+1];
            char l=row[i][y[i]],r=row[i][y[i]+1];
            b[i][j]=(u=='v' || d=='^' || l=='>' || r=='<');
        }
    }
    vvi d(h,vi(w,inf));
    queue<pii> q;
    d[st.f][st.s]=0;
    q.push(st);
    while (!q.empty()) {
        pii pos=q.front();
        q.pop();
        int dist=d[pos.f][pos.s];
        rep(k,4) {
            auto[i,j]=pos+dir[k];
            if (i<0||h<=i || j<0||w<=j)  continue;
            if (b[i][j]) continue;
            if (chmin(d[i][j],dist+1)) q.push({i,j});
        }
        if (d[go.f][go.s]!=inf) {
            print(d[go.f][go.s]);
            return 0;
        }
    }
    print(-1);

    return 0;
}

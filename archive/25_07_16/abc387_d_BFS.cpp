// https://atcoder.jp/contests/abc387/tasks/abc387_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> str(h);
    cin >> str;
    pii st,go;
    // d[i][j]={上下移動可能な状態で来れる最短距離,左右移動…}
    // -1:不可
    v<v<pii>> d(h,v<pii>(w,{INT_MAX,INT_MAX}));
    rep(i,h)rep(j,w) {
        if (str[i][j]=='#') d[i][j]={-1,-1};
        if (str[i][j]=='S') st={i,j};
        if (str[i][j]=='G') go={i,j};
    }
    // {位置,(0:上下,1:左右)}
    queue<pair<pii,bool>> q;
    d[st.f][st.s]={0,0};
    q.push({st,0});
    q.push({st,1});
    while (!q.empty()) {
        auto[pos,b]=q.front();
        q.pop();
        auto[x,y]=pos;
        if (b) {
            if (0<=y-1 && chmin(d[x][y-1].f,d[x][y].s+1)) q.push({{x,y-1},0});
            if (y+1<w && chmin(d[x][y+1].f,d[x][y].s+1)) q.push({{x,y+1},0});
        } else {
            if (0<=x-1 && chmin(d[x-1][y].s,d[x][y].f+1)) q.push({{x-1,y},1});
            if (x+1<h && chmin(d[x+1][y].s,d[x][y].f+1)) q.push({{x+1,y},1});
        }
    }
    int mi=min(d[go.f][go.s].f,d[go.f][go.s].s);
    print(mi==INT_MAX?-1:mi);

    return 0;
}

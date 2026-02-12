// https://atcoder.jp/contests/abc272/tasks/abc272_d

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<pii> dir;
    for (int i=0; i*i*2<=m; ++i) {
        int j=sqrt(m-i*i);
        if (i*i+j*j!=m) continue;
        dir.pb({i,j});
    }
    int l=dir.size();
    rep(i,l) {
        auto[x,y]=dir[i];
        dir.pb({x,-y});
        dir.pb({-x,y});
        dir.pb({-x,-y});
        dir.pb({y,x});
        dir.pb({y,-x});
        dir.pb({-y,x});
        dir.pb({-y,-x});
    }
    sort(all(dir));
    uniq(dir);

    vvi a(n,vi(n,INF));
    // {距離,i,j}
    priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>> q;
    a[0][0]=0;
    q.push({0,0,0});
    while (!q.empty()) {
        auto[d,i,j]=q.top();
        q.pop();
        if (a[i][j]<d) continue;
        for (auto[x,y]:dir) {
            int ni=i+x,nj=j+y;
            if (OutOfGrid({ni,nj},{n,n})) continue;
            if (chmin(a[ni][nj],d+1)) q.push({a[ni][nj],ni,nj});
        }
    }
    rep(i,n) {
        rep(j,n) cout<<((a[i][j]==INF)?-1:a[i][j])<<' ';
        cout<<endl;
    }

    return 0;
}

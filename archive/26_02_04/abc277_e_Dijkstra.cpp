// https://atcoder.jp/contests/abc277/tasks/abc277_e

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vector g(n,v<pii>());
    rep(i,m) {
        int u,v,a;
        cin >> u >> v >> a;
        --u,--v;
        g[u].pb({v,a});
        g[v].pb({u,a});
    }
    vb sw(n,0);
    rep(i,k) {
        int s;
        cin >> s;
        sw[--s]=1;
    }
    // d[i][j]:頂点iにスイッチ状態jで到達する最短移動回数
    vvi d(n,vi(2,INF));
    // {距離,{位置}}
    priority_queue<pair<int,pii>,v<pair<int,pii>>,greater<>> q;
    d[0][0]=0;
    q.push({0,{0,0}});
    while (!q.empty()) {
        auto [dist,p]=q.top();
        q.pop();
        auto[pos,b]=p;
        if (d[pos][b]<dist) continue;
        // 反転を単体でする場合、少し遅くなる
        // if (sw[pos] && chmin(d[pos][!b],d[pos][b])) q.push({d[pos][!b],{pos,!b}});
        for (auto[nxt,nb]:g[pos]) {
            if (b!=nb && chmin(d[nxt][b],d[pos][b]+1)) q.push({d[nxt][b],{nxt,b}});
            if (sw[pos] && b==nb && chmin(d[nxt][!b],d[pos][b]+1)) q.push({d[nxt][!b],{nxt,!b}});
        }
    }
    int ans=min(d[n-1]);
    print(ans==INF?-1:ans);

    return 0;
}

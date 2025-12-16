// https://atcoder.jp/contests/abc294/tasks/abc294_g

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vvi g;
v<unordered_map<int,int>> c;
// 辺のecostのインデックス {小,大}が行き、{大,小}が帰り
map<pii,int> mp;
vb b;
vi tin,tout,ecost;
v<pii> depth;
void dfs(int n,int& i,int d) {
    b[n]=1;
    tin[n]=i;
    for (int nxt:g[n]) {
        if (b[nxt]) continue;
        int a=min(n,nxt), bb=max(n,nxt);
        ecost.pb(c[n][nxt]);
        depth.pb({d+1,nxt});
        ++i;
        mp[{a,bb}]=i;
        dfs(nxt,i,d+1);
        ++i;
        ecost.pb(-c[n][nxt]);
        depth.pb({d,n});
        mp[{bb,a}]=i;
    }
    tout[n]=i+1;
}

pii op_min(const pii& a,const pii& b){return a.f<b.f?a:b;}
pii e_min(){return {INT_MAX,INT_MAX};}
int op_sum(const int& a,const int& b){return a+b;}
int e_sum(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    g=vvi(n);
    c=v<unordered_map<int,int>>(n);
    v<tuple<int,int,int>> eg(n-1);
    for (auto&[u,v,w]:eg) {
        cin >> u >> v >> w;
        --u,--v;
        g[u].pb(v),g[v].pb(u);
        c[u][v]=c[v][u]=w;
    }

    // Euler Tour
    // 頂点の、[始点,終点)
    tin=tout=vi(n);
    // 辺のコスト(帰りは負)
    ecost=vi(1,0);
    // {深さ,頂点}
    depth=v<pii>(1,{0,0});
    // 訪問済み
    b=vb(n,0);
    int idx=0;
    dfs(0,idx,0);
    ++idx;

    // 最小共通祖先(lca)
    // 2頂点間のパスで、一番浅い深さの頂点
    segtree<pii,op_min,e_min> segMin(idx);
    rep(i,idx) segMin.set(i,depth[i]);
    auto lca=[&](int u,int v){
        int l=min(tin[u],tin[v]),r=max(tin[u],tin[v]);
        return segMin.prod(l,r+1).s;
    };
    // 根からの距離
    segtree<int,op_sum,e_sum> segSum(idx);
    rep(i,idx) segSum.set(i,ecost[i]);
    auto cost=[&](int x){return segSum.prod(0,tout[x]);};

    int q;
    cin >> q;
    while (q--) {
        int m,u,v;
        cin >> m >> u >> v;
        if (m==1) {
            --u;
            auto[x,y,z]=eg[u];
            int a=min(x,y),bb=max(x,y);
            segSum.set(mp[{a,bb}],v);
            segSum.set(mp[{bb,a}],-v);
        } else {
            --u,--v;
            int r=lca(u,v);
            print(cost(u)+cost(v)-cost(r)*2);
        }
    }

    return 0;
}

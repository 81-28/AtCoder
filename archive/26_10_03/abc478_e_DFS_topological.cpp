// https://atcoder.jp/contests/abc478/tasks/abc478_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


vvi g,rg;
vi b,ord,id;
void dfs(int x) {
    b[x]=1;
    for (int nxt:g[x]) {
        if (!b[nxt]) dfs(nxt);
    }
    ord.pb(x);
}
void rdfs(int x,int y) {
    id[x]=y;
    for (int nxt:rg[x]) {
        if (id[nxt]==-1) rdfs(nxt,y);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    g=rg=vvi(n);
    v<tuple<int,int,int>> tu(q);
    for (auto&[t,u,v]:tu) {
        cin >> t >> u >> v;
        --u,--v;
        g[u].pb(v);
        rg[v].pb(u);
    }

    b=vi(n,0);
    rep(i,n) {
        if (!b[i]) dfs(i);
    }

    reverse(all(ord));

    id=vi(n,-1);
    int m=0;
    for (int val:ord) {
        if (id[val]==-1) rdfs(val,m++);
    }

    v<v<pii>> gg(m);
    vi cnt(m,0);
    for (auto[t,u,v]:tu) {
        u=id[u],v=id[v];
        if (u==v) {
            if (t) {
                YesNo(0);
                return 0;
            }
        } else {
            gg[u].pb({v,t});
            ++cnt[v];
        }
    }

    queue<int> qu;
    vi a(m,1);
    rep(i,m) {
        if (!cnt[i]) qu.push(i);
    }
    while (!qu.empty()) {
        int pos=qu.front();
        qu.pop();
        for (auto[nxt,t]:gg[pos]) {
            chmax(a[nxt],a[pos]+t);
            if (!--cnt[nxt]) qu.push(nxt);
        }
    }
    YesNo(1);
    rep(i,n) cout<<a[id[i]]<<' ';
    cout<<endl;

    return 0;
}

// https://atcoder.jp/contests/abc472/tasks/abc472_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class UnionFind {
public:
    // par: 親, siz: サイズ
    vector<int> par,siz;
    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par = vector<int>(n,-1);
        siz = vector<int>(n,1);
    }

    // 頂点xの根を返す関数
    int root(const int& x) {
        if (par[x] == -1) return x; // 親が無いとき、それが根
        else return par[x] = root(par[x]); // 経路圧縮して親に移動
    }

    // 頂点uとvを繋げる関数(sizが大きい方に根を統合)
    // 返り値はsameと同じ
    bool unite(const int& u, const int& v) {
        int rootU = root(u);
        int rootV = root(v);
        if (rootU == rootV) return 1;
        if (siz[rootU] < siz[rootV]) {
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
        }
        return 0;
    }

    // 頂点uとvが同じグループにあるか(同じ根を持つか)を返す関数
    bool same(const int& u, const int& v) {
        return root(u) == root(v);
    }

    // 頂点xが含まれる連結成分の大きさ
    int size(const int& x) {
        return siz[root(x)];
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vvi g(n);
    v<pii> p;
    while (m--) {
        int a,b;
        cin >> a >> b;
        if (!uf.unite(--a,--b)) {
            g[a].pb(b);
            g[b].pb(a);
        } else {
            p.pb({a,b});
        }
    }
    vi c(n,-1);
    queue<int> q;
    c[0]=0;
    q.push(0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (c[nxt]!=-1) continue;
            c[nxt]=c[pos]^1;
            q.push(nxt);
        }
    }
    for (auto[a,b]:p) {
        if (c[a]!=c[b]) continue;
        vi par(n,-1);
        par[a]=a;
        q.push(a);
        while (!q.empty()) {
            int pos=q.front();
            q.pop();
            for (int nxt:g[pos]) {
                if (par[nxt]!=-1) continue;
                par[nxt]=pos;
                q.push(nxt);
            }
        }
        vi ans={a+1};
        for (int now=b; now!=a; now=par[now]) ans.pb(now+1);
        print(ans.size());
        print(ans);
        return;
    }
    print(-1);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

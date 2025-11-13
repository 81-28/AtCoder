// https://atcoder.jp/contests/abc292/tasks/abc292_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


class UnionFind {
public:
    // par: 親, siz: サイズ
    // edg: その頂点が属する連結成分の辺の数
    vector<int> par,siz,edg;
    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par = vi(n,-1);
        siz = vi(n,1);
        edg = vi(n,0);
    }

    // 頂点xの根を返す関数
    int root(const int& x) {
        if (par[x] == -1) return x; // 親が無いとき、それが根
        else return par[x] = root(par[x]); // 経路圧縮して親に移動
    }

    // 頂点uとvを繋げる関数(sizが大きい方に根を統合)
    void unite(const int& u, const int& v) {
        int rootU = root(u);
        int rootV = root(v);
        ++edg[rootU];
        if (rootU == rootV) return;
        if (siz[rootU] < siz[rootV]) {
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
            edg[rootV] += edg[rootU];
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
            edg[rootU] += edg[rootV];
        }
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        --u,--v;
        uf.unite(u,v);
    }
    v<bool> b(n,0);
    rep(i,n) {
        int r=uf.root(i);
        if (b[r]) continue;
        b[r]=1;
        if (uf.siz[r]!=uf.edg[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

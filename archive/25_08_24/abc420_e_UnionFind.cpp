// https://atcoder.jp/contests/abc420/tasks/abc420_e

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")


// cnt[i]:根iが属するグループの黒色頂点数
map<int,int> cnt;
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
    void unite(const int& u, const int& v) {
        int rootU = root(u);
        int rootV = root(v);
        if (rootU == rootV) return;
        if (siz[rootU] < siz[rootV]) {
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
            cnt[rootV] += cnt[rootU];
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
            cnt[rootU] += cnt[rootV];
        }
    }

    // 頂点uとvが同じグループにあるか(同じ根を持つか)を返す関数
    bool same(const int& u, const int& v) {
        return root(u) == root(v);
    }

    int size(const int& x) {
        return siz[root(x)];
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    map<int,bool> b;
    while (q--) {
        int m,u,v;
        cin >> m >> u;
        --u;
        if (m==1) {
            cin >> v;
            --v;
            uf.unite(u,v);
        }
        if (m==2) {
            if (b[u]) --cnt[uf.root(u)];
            else ++cnt[uf.root(u)];
            b[u]=!b[u];
        }
        if (m==3) {
            YesNo(cnt[uf.root(u)]);
        }
    }

    return 0;
}

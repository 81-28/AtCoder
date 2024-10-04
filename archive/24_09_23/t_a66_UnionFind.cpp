// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bn

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


class UnionFind {
public:
    // par: 親, siz: サイズ
    vector<int> par,siz;
    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par = vector<int>(n+1,-1);
        siz = vector<int>(n+1,1);
    }

    // 頂点xの根を返す関数
    int root(int x) {
        if (par[x] == -1) return x; // 親が無いとき、それが根
        else return par[x] = root(par[x]); // 経路圧縮して親に移動

        // 経路圧縮しない場合
        // while (true) {
        //     if (par[x] == -1) break; // 親が無いとき、それが根
        //     x = par[x]; // 親に移動
        // }
        // return x;
    }

    // 頂点uとvを繋げる関数(sizが大きい方に根を統合)
    void unite(const int& u, const int& v) {
        int rootU = root(u);
        int rootV = root(v);
        if (rootU == rootV) return;
        if (siz[rootU] < siz[rootV]) {
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
        }
    }

    // 頂点uとvが同じグループにあるか(同じ根を持つか)を返す関数
    bool same(const int& u, const int& v) {
        return root(u) == root(v);
    }
};

int main() {
    fastio();

    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    int t,u,v;
    rep(k,q) {
        cin >> t >> u >> v;
        if (t == 1) uf.unite(u,v);
        if (t == 2) YesNo(uf.same(u,v));
    }

    return 0;
}

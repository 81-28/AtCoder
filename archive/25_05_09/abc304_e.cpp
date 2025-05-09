// https://atcoder.jp/contests/abc304/tasks/abc304_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}

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

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    pii p;
    rep(i,m) {
        cin >> p;
        uf.unite(p.f,p.s);
    }
    int k;
    cin >> k;
    set<pii> ng;
    int a,b;
    rep(i,k) {
        cin >> p;
        a=uf.root(p.f);
        b=uf.root(p.s);
        ng.insert(a<b?pii(a,b):pii(b,a));
    }
    int q;
    cin >> q;
    rep(i,q) {
        cin >> p;
        a=uf.root(p.f);
        b=uf.root(p.s);
        YesNo(ng.find(a<b?pii(a,b):pii(b,a))==ng.end());
    }

    return 0;
}

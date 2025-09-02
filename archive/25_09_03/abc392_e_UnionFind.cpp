// https://atcoder.jp/contests/abc392/tasks/abc392_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

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

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    UnionFind uf(n+1);
    // {ケーブル番号,サーバーa,サーバーb}
    v<tuple<int,int,int>> t;
    rep1(i,m) {
        int a,b;
        cin >> a >> b;
        if (uf.same(a,b)) t.pb({i,a,b});
        else uf.unite(a,b);
    }
    set<int> r;
    rep1(i,n) r.insert(uf.root(i));
    int l=r.size()-1;
    print(l);
    int i=0;
    for (auto[j,a,b]:t) {
        if (i==l) break;
        int rt=uf.root(a);
        auto it=r.upper_bound(rt);
        if (it==r.end()) {
            it=r.lower_bound(rt);
            --it;
        }
        int c=*it;
        if (!uf.same(a,c)) {
            r.erase(it);
            print(j,a,c);
            uf.unite(a,c);
            ++i;
        }
    }

    return 0;
}

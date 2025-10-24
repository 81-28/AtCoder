// https://atcoder.jp/contests/abc372/tasks/abc372_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi merge(vi a,const vi& b) {
    for (int val:b) a.pb(val);
    sort(rall(a));
    int n=a.size();
    vi res;
    rep(i,min(n,10)) res.pb(a[i]);
    return res;
}

class UnionFind {
public:
    // par: 親, siz: サイズ
    vector<int> par,siz;
    vvi top;
    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par = vector<int>(n,-1);
        siz = vector<int>(n,1);
        top = vvi(n);
        rep(i,n) top[i].pb(i);
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
            top[rootV]=merge(top[rootV],top[rootU]);
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
            top[rootU]=merge(top[rootU],top[rootV]);
        }
    }

    int query(const int& u, const int& k) {
        vi vec=top[root(u)];
        if (vec.size()<k) return -2;
        return vec[k-1];
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int m,u,v;
        cin >> m >> u >> v;
        if (m==1) uf.unite(--u,--v);
        else print(uf.query(--u,v)+1);
    }

    return 0;
}

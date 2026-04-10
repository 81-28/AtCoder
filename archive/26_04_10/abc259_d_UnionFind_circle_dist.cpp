// https://atcoder.jp/contests/abc259/tasks/abc259_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


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
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    pii s,t;
    cin >> s >> t;
    v<tuple<int,int,int>> c(n);
    for (auto&[x,y,r]:c) cin >> x >> y >> r;
    UnionFind uf(n+2);
    auto[a,b]=s;
    auto[d,e]=t;
    rep(i,n) {
        auto[x,y,r]=c[i];
        if ((a-x)*(a-x)+(b-y)*(b-y)==r*r) uf.unite(0,i+1);
        if ((d-x)*(d-x)+(e-y)*(e-y)==r*r) uf.unite(n+1,i+1);
    }
    rep(i,n-1) {
        auto[xi,yi,ri]=c[i];
        for(int j=i+1; j<n; ++j) {
            auto[xj,yj,rj]=c[j];
            if ((xj-xi)*(xj-xi)+(yj-yi)*(yj-yi)>(rj+ri)*(rj+ri)) continue;
            if ((xj-xi)*(xj-xi)+(yj-yi)*(yj-yi)<(rj-ri)*(rj-ri)) continue;
            uf.unite(i+1,j+1);
        }
    }
    YesNo(uf.same(0,n+1));

    return 0;
}

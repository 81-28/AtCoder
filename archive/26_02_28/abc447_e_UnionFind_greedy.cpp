// https://atcoder.jp/contests/abc447/tasks/abc447_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
using mint=modint998244353;

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

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<pii> p(m);
    UnionFind uf(n);
    for (auto&[u,v]:p) {
        cin >> u >> v;
        --u,--v;
    }
    if (n==2) {
        print(2);
        return 0;
    }
    mint ans=0;
    int cnt=n;
    // スコアが大きい順に消さずに済むかを確認
    for (int i=m-1; i>=0; --i) {
        auto[u,v]=p[i];
        if (!uf.unite(u,v)) --cnt;
        // 連結成分が2となる時、それ以下で消さずに済む辺は消さない
        if (cnt==2) {
            for (int j=i; j>=0; --j) {
                auto[a,b]=p[j];
                if (!uf.same(a,b)) ans+=mint(2).pow(j+1);
            }
            break;
        }
    }
    print(ans.val());

    return 0;
}

// https://atcoder.jp/contests/arc226/tasks/arc226_a

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

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


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    for (auto&[l,r]:p) cin >> l >> r;
    v<pii> idx(n*2,{-1,-1});
    bool ok=1;
    rep(i,n) {
        auto[l,r]=p[i];
        for (int j=l-1; j<r; ++j) {
            if (idx[j].f==-1) {
                idx[j].f=i;
                continue;
            }
            if (idx[j].s==-1) {
                idx[j].s=i;
                continue;
            }
            ok=0;
            break;
        }
        if (!ok) break;
    }
    if (!ok) {
        print(0);
        return 0;
    }
    UnionFind uf(n);
    for (auto[a,b]:idx) {
        if (b==-1) continue;
        uf.unite(a,b);
    }
    mint ans=1;
    rep(i,n) {
        if (uf.root(i)!=i) continue;
        ans*=2;
    }
    print(ans.val());

    return 0;
}

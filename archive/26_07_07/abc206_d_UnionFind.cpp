// https://atcoder.jp/contests/abc206/tasks/abc206_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
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
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    UnionFind uf(n);
    for (int l=0,r=n-1; l<r; ++l,--r) uf.unite(l,r);
    map<int,vi> m;
    rep(i,n) m[a[i]].pb(i);
    for (auto[val,vec]:m) {
        int siz=vec.size();
        rep(i,siz-1) uf.unite(vec[i],vec[i+1]);
    }
    set<int> s;
    rep(i,n) {
        s.insert(uf.root(i));
    }
    // 最初の色数-最終的な色数
    print(m.size()-s.size());

    return 0;
}

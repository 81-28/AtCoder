// https://atcoder.jp/contests/abc311/tasks/abc311_c

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


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

    ll n;
    cin >> n;
    UnionFind uf(n);
    vll a(n+1);
    ll s;
    rep1(i,n) {
        cin >> a[i];
        if (uf.same(i,a[i])) s=i;
        else uf.unite(i,a[i]);
    }
    vll b;
    b.pb(s);
    for (ll i=a[s]; i!=s; i=a[i]) b.pb(i);
    print(b.size());
    print(b);

    return 0;
}

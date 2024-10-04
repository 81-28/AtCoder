// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bo

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;
using pii = pair<int,int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


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

int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    vi a(m),b(m);
    int c;
    v<pii> edgeList;
    rep(i,m) {
        cin >> a[i] >> b[i] >> c;
        edgeList.pb(pii({c,i}));
    }
    // コストが低い順にソート
    sort(all(edgeList));

    UnionFind uf(n);
    int ans = 0;
    int u,v,cost;
    rep(i,m) {
        int j = edgeList[i].second;
        u = a[j], v = b[j];
        cost = edgeList[i].first;
        // 2辺が別のグループに属している場合、繋げる
        if (!uf.same(u,v)) {
            uf.unite(u,v);
            ans += cost;
        }
    }
    print(ans);

    return 0;
}

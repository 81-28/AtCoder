// https://atcoder.jp/contests/abc351/tasks/abc351_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

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

    int size(const int& x) {
        return siz[root(x)];
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    vvi a(h,vi(w,0));
    rep(i,h)rep(j,w) {
        if (s[i][j]=='#'
            || (i&&s[i-1][j]=='#')
            || (i+1<h&&s[i+1][j]=='#')
            || (j&&s[i][j-1]=='#')
            || (j+1<w&&s[i][j+1]=='#')) a[i][j]=1;
    }
    UnionFind uf(h*w);
    rep(i,h)rep(j,w) {
        if (a[i][j]) continue;
        if (i&&!a[i-1][j])      uf.unite(i*w+j,(i-1)*w+j);
        if (i+1<h&&!a[i+1][j])  uf.unite(i*w+j,(i+1)*w+j);
        if (j&&!a[i][j-1])      uf.unite(i*w+j,i*w+(j-1));
        if (j+1<w&&!a[i][j+1])  uf.unite(i*w+j,i*w+(j+1));
    }
    map<int,int> add;
    rep(i,h)rep(j,w) {
        if (!a[i][j]) continue;
        set<int> r;
        if (i&&!a[i-1][j])      r.insert(uf.root((i-1)*w+j));
        if (i+1<h&&!a[i+1][j])  r.insert(uf.root((i+1)*w+j));
        if (j&&!a[i][j-1])      r.insert(uf.root(i*w+(j-1)));
        if (j+1<w&&!a[i][j+1])  r.insert(uf.root(i*w+(j+1)));
        for (int val:r) ++add[val];
        
    }
    int ans=0;
    rep(i,h)rep(j,w) chmax(ans,a[i][j]=uf.size(i*w+j)+add[uf.root(i*w+j)]);
    print(ans);

    return 0;
}

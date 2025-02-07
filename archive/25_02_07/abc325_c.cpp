// https://atcoder.jp/contests/abc325/tasks/abc325_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


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
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    v<v<bool>> b(h,v<bool>(w,0));
    UnionFind uf(h*w);
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') b[i][j]=1;
        else continue;
        if (j && b[i][j-1]) uf.unite(i*w+j,i*w+(j-1));
        if (i) {
            if (j && b[i-1][j-1]) uf.unite(i*w+j,(i-1)*w+(j-1));
            if (b[i-1][j]) uf.unite(i*w+j,(i-1)*w+j);
            if (j < w-1 && b[i-1][j+1]) uf.unite(i*w+j,(i-1)*w+(j+1));
        }
    }
    unordered_set<int> c;
    rep(i,h)rep(j,w) {
        if (b[i][j]) c.insert(uf.root(i*w+j));
    }
    print(c.size());

    return 0;
}

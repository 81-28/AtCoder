// https://atcoder.jp/contests/abc413/tasks/abc413_g

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

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

    int h,w,k;
    cin >> h >> w >> k;
    v<pii> p(k+1);
    unordered_map<int,unordered_map<int,int>> mp;
    rep1(i,k) {
        auto&[r,c]=p[i];
        cin >> r >> c;
        mp[r][c]=i;
    }
    // 0:左と下,k+1:右と上 の辺
    UnionFind uf(k+2);
    // {idx}
    queue<int> q;
    rep1(i,k) {
        auto[r,c]=p[i];
        if (r==h || c==1) {
            uf.unite(i,0);
            q.push(i);
        }
        if (r==1 || c==w) {
            uf.unite(i,k+1);
            q.push(i);
        }
    }
    while (!q.empty()) {
        int i=q.front();
        q.pop();
        rep(k,8) {
            auto[x,y]=p[i]+dir[k];
            if (x<=0||h<x || y<=0||w<y) continue;
            int j=mp[x][y];
            if (!j) continue;
            if (!uf.unite(i,j)) q.push(j);
        }
    }
    YesNo(!uf.same(0,k+1));

    return 0;
}

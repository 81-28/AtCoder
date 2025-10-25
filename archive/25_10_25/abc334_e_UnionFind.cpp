// https://atcoder.jp/contests/abc334/tasks/abc334_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class UnionFind {
public:
    // par: 親, siz: サイズ
    vector<int> par,siz;
    // 連結成分数
    int cnt;
    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par = vector<int>(n,-1);
        siz = vector<int>(n,1);
        cnt=0;
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
        --cnt;
        if (siz[rootU] < siz[rootV]) {
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
        }
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    UnionFind uf(h*w);
    queue<pii> q;
    rep(i,h)rep(j,w) {
        if (st[i][j]=='.') {
            q.push({i,j});
            continue;
        }
        int x=i+1,y=j;
        if (x<h && st[x][y]=='#') uf.unite(w*i+j,w*x+y);
        x=i,y=j+1;
        if (y<w && st[x][y]=='#') uf.unite(w*i+j,w*x+y);
    }
    int r=q.size(),sm=0;
    uf.cnt+=h*w-r;
    while(!q.empty()) {
        pii pos=q.front();
        q.pop();
        set<int> se;
        rep(i,4) {
            auto[x,y]=pos+dir[i];
            if (x<0||h<=x||y<0||w<=y) continue;
            if (st[x][y]=='.') continue;
            se.insert(uf.root(w*x+y));
        }
        sm+=uf.cnt-(se.size()-1);
    }
    mint ans=(mint)sm/r;
    print(ans.val());

    return 0;
}
// https://atcoder.jp/contests/abc219/tasks/abc219_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
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

    int n=4;
    vvi a(n,vi(n));
    cin >> a;
    int mx=1<<16;
    int ans=0;
    rep(k,mx) {
        bool ok=1;
        rep(i,n*n) {
            int x=i/n,y=i%n;
            if (!a[x][y]) continue;
            if (!((k>>i)&1)) {
                ok=0;
                break;
            }
        }
        // 村が含まれない場合
        if (!ok) continue;
        UnionFind uf(n*n);
        rep(i,n)rep(j,n) {
            if (!((k>>(i*n+j))&1)) continue;
            if (i+1<n && (k>>((i+1)*n+j))&1) uf.unite(i*n+j,(i+1)*n+j);
            if (j+1<n && (k>>(i*n+(j+1)))&1) uf.unite(i*n+j,i*n+(j+1));
        }
        set<int> st;
        int cnt=0;
        rep(i,n*n) {
            if (!((k>>i)&1)) continue;
            ++cnt;
            st.insert(uf.root(i));
        }
        // 全てが繋がっていない場合
        if (st.size()>1) continue;
        int m=n+2;
        uf=UnionFind(m*m);
        vvb b(m,vb(m,0));
        queue<pii> q;
        b[0][0]=1;
        ++cnt;
        q.push({0,0});
        while (!q.empty()) {
            pii p=q.front();
            q.pop();
            rep(i,4) {
                auto[x,y]=p+dir[i];
                if (OutOfGrid({x,y},{m,m})) continue;
                if (b[x][y]) continue;
                if (0<x && x<5 && 0<y && y<5 && (k>>((x-1)*n+(y-1)))&1) continue;
                b[x][y]=1;
                ++cnt;
                q.push({x,y});
            }
        }
        // 穴空きの場合
        if (cnt!=m*m) continue;
        ++ans;
    }
    print(ans);

    return 0;
}

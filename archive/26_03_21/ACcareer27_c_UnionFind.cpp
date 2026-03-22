// https://atcoder.jp/contests/ACcareer27/tasks/ACcareer27_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
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
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    UnionFind uf(h*w);
    vvb b(h,vb(w,0));
    v<pii> bo;
    rep(i,h)rep(j,w) {
        if (st[i][j]=='B') bo.pb({i,j});
        if (!(b[i][j]=(st[i][j]=='.'))) continue;
        if (i && b[i-1][j]) uf.unite((i-1)*w+j,i*w+j);
        if (j && b[i][j-1]) uf.unite(i*w+(j-1),i*w+j);
    }
    int n=bo.size();
    map<int,int> cnt;
    rep(i,n) {
        set<int> st;
        rep(k,4) {
            auto[x,y]=bo[i]+dir[k];
            if (OutOfGrid({x,y},{h,w})) continue;
            if (!b[x][y]) continue;
            int r=uf.root(x*w+y);
            st.insert(r);
        }
        for (int val:st) {
            if (++cnt[val]==n) {
                YesNo(1);
                return 0;
            }
        }
    }
    YesNo(0);

    return 0;
}

// https://atcoder.jp/contests/abc328/tasks/abc328_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
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
};

// m個の内n個を選ぶ全パターン,インデックスは昇順
vvi combi(const int& n,const int& r) {
    vvi res;
    vi vec(r);
    rep(i,r) vec[i]=i;
    res.pb(vec);
    while (1) {
        bool c=0;
        rep(i,r) {
            if (vec[i]==n-r+i) {
                if (i==0) return res;
                c=1;
                ++vec[i-1];
                for (int j=i; j<r; ++j) vec[j]=vec[j-1]+1;
                break;
            }
        }
        if (!c) ++vec[r-1];
        res.pb(vec);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    v<pii> p(m);
    map<pii,int> mp;
    rep(i,m) {
        int w;
        cin >> p[i] >> w;
        --p[i];
        mp[p[i]]=w;
    }
    // n-1辺を選んで、コストを計算
    vvi com=combi(m,n-1);
    int ans=LLONG_MAX;
    for (vi vec:com) {
        UnionFind uf(n);
        bool ok=1;
        int sm=0;
        for (int i:vec) {
            auto[u,v]=p[i];
            if (uf.same(u,v)) {
                ok=0;
                break;
            }
            uf.unite(u,v);
            sm+=mp[{u,v}];
            sm%=k;
        }
        if (ok) chmin(ans,sm);
    }
    print(ans);

    return 0;
}

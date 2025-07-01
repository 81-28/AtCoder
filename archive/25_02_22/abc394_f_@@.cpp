// https://atcoder.jp/contests/abc394/tasks/abc394_f

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define f first
#define s second
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
using ll=long long;
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// using mint=modint1000000007;
// using mint=modint998244353;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}
// #define max(...) (*max_element({__VA_ARGS__}))
// #define min(...) (*min_element({__VA_ARGS__}))


class UnionFind {
public:
    // par: 親, siz: サイズ
    vector<ll> par,siz;
    // n頂点のUnion-Find
    UnionFind(const ll& n) {
        par = vector<ll>(n+1,-1);
        siz = vector<ll>(n+1,1);
    }

    // 頂点xの根を返す関数
    ll root(ll x) {
        if (par[x] == -1) return x; // 親が無いとき、それが根
        else return par[x] = root(par[x]); // 経路圧縮して親に移動
    }

    // 頂点uとvを繋げる関数(sizが大きい方に根を統合)
    void unite(const ll& u, const ll& v) {
        ll rootU = root(u);
        ll rootV = root(v);
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
    bool same(const ll& u, const ll& v) {
        return root(u) == root(v);
    }
};


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vvll g(n+1);
    v<pll> p(n-1);
    rep(i,n-1) {
        cin >> p[i].f >> p[i].s;
        g[p[i].f].pb(p[i].s);
        g[p[i].s].pb(p[i].f);
    }
    UnionFind uf(n);
    ll ans=0;
    ll u,v;
    vll d(n+1,0);
    ll du,dv;
    ll r=0;
    rep(i,n-1) {
        u=p[i].f,v=p[i].s;
        if (g[u].size() >= 4 && g[v].size() >= 4) {
            if (uf.same(u,v)) {
                d[uf.root(u)] -= 2;
            } else {
                du=d[uf.root(u)],dv=d[uf.root(v)];
                uf.unite(u,v);
                d[uf.root(u)] += du+dv;
            }
            // ans = max(ans,uf.siz[uf.root(u)]);
            if (ans < uf.siz[uf.root(u)]) {
                ans = uf.siz[uf.root(u)];
                r=uf.root(u);
            }
        } else {
            if (g[u].size() >= 4) {
                if (ans==0) {
                    ans=1;
                    r=u;
                }
            }
            if (g[v].size() >= 4) {
                if (ans==0) {
                    ans=1;
                    r=v;
                }
            }
        }
    }
    // rep1(i,n) cout<<uf.siz[uf.root(i)]<<' ';
    // cout<<'\n';
    if (ans==0) print(-1);
    else print(ans*3+2 + d[r]);

    return 0;
}

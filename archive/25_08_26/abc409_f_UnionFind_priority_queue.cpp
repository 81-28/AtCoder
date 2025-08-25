// https://atcoder.jp/contests/abc409/tasks/abc409_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
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

    int n,q;
    cin >> n >> q;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    // {距離,i,j}
    priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>> pq;
    rep(i,n-1) for(int j=i+1; j<n; ++j) {
        pq.push({abs(p[i].f-p[j].f)+abs(p[i].s-p[j].s),i,j});
    }
    UnionFind uf(n+q);
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            pii pp;
            cin >> pp;
            p.pb(pp);
            ++n;
            rep(i,n-1) pq.push({abs(p[i].f-p[n-1].f)+abs(p[i].s-p[n-1].s),i,n-1});
        }
        if (m==2) {
            int d=INT_MAX;
            while (!pq.empty()) {
                auto[dist,i,j]=pq.top();
                if (uf.same(i,j)) {
                    pq.pop();
                    continue;
                }
                if (chmin(d,dist) || d==dist) {
                    uf.unite(i,j);
                    pq.pop();
                } else break;
            }
            print(d==INT_MAX?-1:d);
        }
        if (m==3) {
            pii pp;
            cin >> pp;
            YesNo(uf.same(pp.f-1,pp.s-1));
        }
    }

    return 0;
}

// https://atcoder.jp/contests/abc408/tasks/abc408_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

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

int log2_int(int n) {
    int i=-1;
    for (; n>0; n>>=1) ++i;
    return i;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // {ラベル,頂点,頂点}
    priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>> pq;
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({c,a,b});
    }
    // 今残っている辺を昇順に接続し、1とnが繋がった時点で最上位桁を確定させる
    // それより上の桁を使う辺を除外し、最上位桁を考えないラベルとして新しい辺集合とする
    // 全て確定するまで行う
    int ans=0;
    int ceil=(1<<30)-1;
    int pw=0;
    while (ceil-pw) {
        UnionFind uf(n+1);
        v<tuple<int,int,int>> vec;
        ceil=(1<<30)-1;
        while (!pq.empty()) {
            auto[c,a,b]=pq.top();
            pq.pop();
            if (c>ceil) break;
            vec.pb({c,a,b});
            if (uf.same(1,n)) continue;
            uf.unite(a,b);
            if (uf.same(1,n)) {
                int l=log2_int(c);
                if (l==-1) {
                    ceil=pw=0;
                } else {
                    ceil=(1<<(l+1))-1;
                    pw=(1<<l);
                }
                ans|=pw;
            }
        }
        pq=priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>>();
        int bit=ceil-pw;
        for (auto [c,a,b]:vec) pq.push({c&bit,a,b});
    }
    print(ans);

    return 0;
}

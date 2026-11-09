// https://atcoder.jp/contests/abc183/tasks/abc183_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class UnionFind {
public:
    // par[x]: 根なら -成分サイズ、根以外なら親
    vector<int> par;
    // c[x][y]:xと同じ成分の中の、クラスyの生徒の人数
    v<unordered_map<int,int>> cnt;

    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par=vector<int>(n,-1);
        cnt=v<unordered_map<int,int>>(n);
    }

    // 頂点xの根を返す（経路圧縮）
    int root(const int& x) {
        if(par[x]<0) return x;
        return par[x]=root(par[x]);
    }

    // 頂点uとvを統合（サイズが大きい方を根にする）
    // 返り値はsameと同じで、既に同じ成分ならtrue
    bool unite(const int& u,const int& v) {
        int a=root(u),b=root(v);
        if(a==b) return 1;
        if(par[a]>par[b]) swap(a,b);
        par[a]+=par[b];
        par[b]=a;
        // 成分ごとの情報を統合
        for (auto[num,c]:cnt[b]) cnt[a][num]+=c;
        return 0;
    }

    int count(const int& x,const int& y) {
        return cnt[root(x)][y];
    }
};


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    rep(i,n) {
        int c;
        cin >> c;
        ++uf.cnt[i][--c];
    }
    while (q--) {
        int m,x,y;
        cin >> m >> x >> y;
        --x,--y;
        if (m&1) uf.unite(x,y);
        else print(uf.count(x,y));
    }

    return 0;
}

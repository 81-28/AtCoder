#include<vector>
using namespace std;


// Union-Find
class UnionFind {
public:
    // par[x]: 根なら -成分サイズ、根以外なら親
    vector<int> par;

    // // 成分ごとの情報（必要な場合のみ使用）
    // // 成分の合計
    // vector<int> sm;

    // n頂点のUnion-Find
    UnionFind(const int& n) {
        // 1-indexedならn+1にする
        par=vector<int>(n,-1);
        // sm=vector<int>(n,0);
    }

    // // 各頂点の初期値を指定
    // UnionFind(const vector<int>& a) {
    //     par=vector<int>(a.size(),-1);
    //     sm=a;
    // }

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
        // // 成分ごとの情報を統合
        // sm[a]+=sm[b];
        return 0;
    }

    // 同じ成分か
    bool same(const int& u,const int& v) {
        return root(u)==root(v);
    }

    // 成分のサイズ
    int size(const int& x) {
        return -par[root(x)];
    }

    // 各連結成分に属する頂点を列挙
    // 1-indexedならgroups(1)
    vector<vector<int>> groups(int start=0) {
        vector<vector<int>> g(par.size());
        for(int i=start;i<(int)par.size();++i) {
            g[root(i)].push_back(i);
        }
        vector<vector<int>> res;
        for(auto& v:g) {
            if(!v.empty()) res.push_back(move(v));
        }
        return res;
    }

    // // 成分の合計
    // int sum(const int& x) {
    //     return sm[root(x)];
    // }

    // // 頂点xの値をd増やす
    // void add(const int& x,const int& d) {
    //     sm[root(x)]+=d;
    // }
};

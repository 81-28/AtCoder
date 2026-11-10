// https://atcoder.jp/contests/abc328/tasks/abc328_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化


class UnionFind {
public:
    // par[x]: 根なら -成分サイズ、根以外なら親
    vi par;
    // d[x]: X_x - X_親（root()実行後は X_x - X_根）
    vi d;

    UnionFind(const int& n) {
        par=vi(n,-1);
        d=vi(n,0);
    }

    // 根を返し、経路圧縮と同時に根との差を計算
    int root(const int& a) {
        if(par[a]<0) return a;
        int p=par[a];
        par[a]=root(p); // 先に親と根の差を確定させる
        d[a]+=d[p];     // (xと親の差) + (親と根の差)
        return par[a];
    }

    // X_a - X_b = w を追加（矛盾する場合はfalse）
    bool unite(const int& a,const int& b,const int& w) {
        int x=root(a),y=root(b);
        // yをxの子にする場合の重み：X_y - X_x
        // X_u - X_b = (d[a]+X_x) - (d[b]+X_y) = w
        int diff=d[a]-d[b]-w;
        // 既に連結している場合、制約を満たすか判定
        if(x==y) return diff==0;

        // Union by Size：小さい成分を大きい成分に結合
        if(par[x]>par[y]) {
            swap(x,y);
            diff=-diff; // 親子を逆にするため、差の符号も反転
        }
        par[x]+=par[y]; // 成分サイズを更新
        par[y]=x;       // yをxの子にする
        d[y]=diff;      // X_y - X_x を記録

        return 1;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    rep1(i,q) {
        int a,b,d;
        cin >> a >> b >> d;
        if (uf.unite(--a,--b,d)) cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}

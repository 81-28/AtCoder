// https://atcoder.jp/contests/abc482/tasks/abc482_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<=b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
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

    int n;
    cin >> n;
    vvi g(n);
    rep(i,n-1) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vvi c(n);
    rep(i,n) {
        int col;
        cin >> col;
        c[--col].pb(i);
    }

    // 直径を求める
    int idx=0,dia=0;
    // 距離
    vi d;
    queue<int> q;
    vi par(n,-1);
    rep(i,2) {
        d=vi(n,n);
        d[idx]=0;
        q.push(idx);
        while (!q.empty()) {
            int pos=q.front();
            q.pop();
            for (int nxt:g[pos]) {
                if (d[nxt]!=n) continue;
                par[nxt]=pos;
                if (chmax(dia,d[nxt]=d[pos]+1)) idx=nxt;
                q.push(nxt);
            }
        }
    }

    // 距離が 直径/2 となる頂点同士で、
    // 別の連結成分のものが、直径と同じ長さのパスをなす

    // 木の中心を求める
    if (dia&1) {
        vi mid;
        for (int pos=idx; pos!=-1; pos=par[pos]) {
            if (d[pos]==dia/2+1) mid.pb(pos);
            if (d[pos]==dia/2) {
                mid.pb(pos);
                break;
            }
        }
        d=vi(n,n);
        for (int pos:mid) {
            d[pos]=0;
            q.push(pos);
        }
    } else {
        int mid=0;
        for (int pos=idx; pos!=-1; pos=par[pos]) {
            if (d[pos]==dia/2) {
                mid=pos;
                break;
            }
        }
        d=vi(n,n);
        d[mid]=0;
        for (int pos:g[mid]) {
            d[pos]=1;
            q.push(pos);
        }
    }
    UnionFind uf(n);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (d[nxt]!=n) continue;
            d[nxt]=d[pos]+1;
            uf.unite(pos,nxt);
            q.push(nxt);
        }
    }

    int ans=0;
    vi cnt(n,0);
    for (vi vec:c) {
        int sm=0;
        vi use;
        for (int val:vec) {
            if (d[val]!=dia/2) continue;
            ++sm;
            int r=uf.root(val);
            if (!cnt[r]) use.pb(r);
            ++cnt[r];
        }
        for (int r:use) {
            ans+=cnt[r]*(sm-cnt[r]);
            cnt[r]=0;
        }
    }
    print(ans/2);

    return 0;
}

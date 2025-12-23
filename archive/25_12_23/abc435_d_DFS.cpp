// https://atcoder.jp/contests/abc435/tasks/abc435_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


vvi g;
vb b;
// O(n)頂点と繋がった頂点に対して、q回dfsすると、グラフのループがO(n*q)となるのでチェックする
void dfs(int n) {
    if (b[n]) return;
    b[n]=1;
    for (int nxt:g[n]) {
        if (b[nxt]) continue;
        dfs(nxt);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    g=vvi(n);
    while (m--) {
        int x,y;
        cin >> x >> y;
        g[--y].pb(--x);
    }
    b=vb(n,0);
    int q;
    cin >> q;
    while (q--) {
        int o,v;
        cin >> o >> v;
        if (o==1) dfs(--v);
        else YesNo(b[--v]);
    }

    return 0;
}

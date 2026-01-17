// https://atcoder.jp/contests/abc441/tasks/abc441_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back


int s,t;
// 行先,コスト
v<v<pii>> g;
vb ans;
void dfs(int pos,int cost,int r) {
    if (r==0) {
        if (s<=cost&&cost<=t) ans[pos]=1;
        return;
    }
    for (auto[nxt,c]:g[pos]) {
        dfs(nxt,cost+c,r-1);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,l;
    cin >> n >> m >> l >> s >> t;
    g=v<v<pii>>(n);
    ans=vb(n,0);
    rep(i,m) {
        int u,v,c;
        cin >> u >> v >> c;
        g[--u].pb({--v,c});
    }
    dfs(0,0,l);
    rep(i,n) {
        if (ans[i]) cout<<i+1<<' ';
    }
    cout<<endl;

    return 0;
}

// https://atcoder.jp/contests/abc448/tasks/abc448_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


vi a;
vvi g;
vb b,ans;
map<int,int> mp;
int d=0;
void dfs(int m) {
    b[m]=1;
    if (++mp[a[m]]==2) ++d;
    ans[m]=d>0;
    for (int nxt:g[m]) {
        if (b[nxt]) continue;
        dfs(nxt);
    }
    if (--mp[a[m]]==1) --d;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    a=vi(n);
    cin >> a;
    g=vvi(n);
    b=vb(n,0);
    ans=vb(n);
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    rep(i,n) YesNo(ans[i]);

    return 0;
}

// https://atcoder.jp/contests/abc239/tasks/abc239_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vvi x;
vvi g;
vb d;
void dfs(int n) {
    d[n]=1;
    vi vec=x[n];
    for (int nxt:g[n]) {
        if (d[nxt]) continue;
        dfs(nxt);
        for (int val:x[nxt]) vec.pb(val);
    }
    sort(rall(vec));
    int l=vec.size();
    vi res;
    rep(i,min(l,20)) res.pb(vec[i]);
    x[n]=res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    x=vvi(n,vi(1));
    cin >> x;
    g=vvi(n);
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        g[--a].pb(--b);
        g[b].pb(a);
    }
    d=vb(n,0);
    dfs(0);
    while (q--) {
        int m,k;
        cin >> m >> k;
        print(x[--m][--k]);
    }

    return 0;
}

// https://atcoder.jp/contests/abc350/tasks/abc350_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


vvi g;
v<bool> b;
map<int,int> mp;
void dfs(const int& n,const int& p) {
    b[n]=1;
    ++mp[p];
    for (int nxt:g[n]) {
        if (!b[nxt]) dfs(nxt,p);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    g=vvi(n);
    b=v<bool>(n,0);
    rep(i,m) {
        pii p;
        cin >> p;
        --p;
        g[p.f].pb(p.s);
        g[p.s].pb(p.f);
    }
    rep(i,n) {
        if (!b[i]) dfs(i,i);
    }
    int ans=-m;
    for (auto p:mp) {
        ans+=p.s*(p.s-1)/2;
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc442/tasks/abc442_c

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

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n);
    while (m--) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi ans(n);
    rep(i,n) {
        int l=n-1-g[i].size();
        ans[i]=l*(l-1)*(l-2)/6;
    }
    print(ans);

    return 0;
}

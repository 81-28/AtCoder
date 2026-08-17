// https://atcoder.jp/contests/abc187/tasks/abc187_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    v<pii> p(n-1);
    vvi g(n);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi d(n,n);
    queue<int> qu;
    d[0]=0;
    qu.push(0);
    vvi gg(n);
    while (!qu.empty()) {
        int pos=qu.front();
        qu.pop();
        for (int nxt:g[pos]) {
            if (chmin(d[nxt],d[pos]+1)) {
                qu.push(nxt);
                gg[pos].pb(nxt);
            }
        }
    }

    vi c(n,0);
    int q;
    cin >> q;
    while (q--) {
        int t,e,x;
        cin >> t >> e >> x;
        auto[a,b]=p[--e];
        if (t&1) {
            if (d[a]<d[b]) c[0]+=x,c[b]-=x;
            else c[a]+=x;
        } else {
            if (d[a]<d[b]) c[b]+=x;
            else c[0]+=x,c[a]-=x;
        }
    }

    qu.push(0);
    while (!qu.empty()) {
        int pos=qu.front();
        qu.pop();
        for (int nxt:gg[pos]) {
            c[nxt]+=c[pos];
            qu.push(nxt);
        }
    }
    for (int val:c) print(val);

    return 0;
}

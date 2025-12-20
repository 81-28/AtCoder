// https://atcoder.jp/contests/abc437/tasks/abc437_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define f first


v<v<pii>> p;
void dfs(vi n) {
    v<pii> q;
    for (int i:n) q.insert(q.end(),all(p[i]));
    sort(all(q));
    int l=q.size();
    vi d;
    rep(i,l) {
        auto[y,j]=q[i];
        cout<<j<<' ';
        d.pb(j);
        if (i==l-1) dfs(d);
        else {
            int yy=q[i+1].f;
            if (y!=yy) {
                dfs(d);
                d.clear();
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    p=v<v<pii>>(n+1);
    rep1(i,n) {
        int x,y;
        cin >> x >> y;
        p[x].pb({y,i});
    }
    dfs({0});
    cout<<endl;

    return 0;
}

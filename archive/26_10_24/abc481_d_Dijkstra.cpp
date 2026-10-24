// https://atcoder.jp/contests/abc481/tasks/abc481_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,s,t;
    cin >> n >> m >> s >> t;
    --s,--t;
    vvi g(n);
    while (m--) {
        int a,b;
        cin >> a >> b;
        g[--a].pb(--b);
    }
    vi d(n,n);
    priority_queue<pii,v<pii>,greater<>> q;
    d[s]=0;
    q.push({d[s],s});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (d[pos]<dist) continue;
        int l=g[pos].size();
        if (!l) continue;
        sort(all(g[pos]));
        int nxt=g[pos][0];
        if (chmin(d[nxt],dist)) q.push({d[nxt],nxt});
        for (int i=1; i<l; ++i) {
            nxt=g[pos][i];
            if (chmin(d[nxt],dist+1)) q.push({d[nxt],nxt});
        }
    }
    print(d[t]==n?-1:d[t]);

    return 0;
}

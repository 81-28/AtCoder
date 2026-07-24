// https://atcoder.jp/contests/abc192/tasks/abc192_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m,x,y;
    cin >> n >> m >> x >> y;
    --x,--y;
    // {行先,かかる時間,発射するタイミング}
    v<v<tuple<int,int,int>>> g(n);
    while (m--) {
        int a,b,t,k;
        cin >> a >> b >> t >> k;
        --a,--b;
        g[a].pb({b,t,k});
        g[b].pb({a,t,k});
    }
    vi d(n,INF);
    // {時間,位置}
    priority_queue<pii,v<pii>,greater<>> q;
    d[x]=0;
    q.push({d[x],x});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (d[pos]<dist) continue;
        for (auto[nxt,t,k]:g[pos]) {
            int quo=dist==0 ? 0:(dist-1)/k+1;
            if (chmin(d[nxt],quo*k+t)) q.push({d[nxt],nxt});
        }
    }
    print(d[y]==INF?-1:d[y]);

    return 0;
}

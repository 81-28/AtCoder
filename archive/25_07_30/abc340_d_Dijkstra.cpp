// https://atcoder.jp/contests/abc340/tasks/abc340_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<v<pii>> g(n+1);
    rep1(i,n-1) {
        int a,b,x;
        cin >> a >> b >> x;
        g[i].pb({i+1,a});
        g[i].pb({x,b});
    }
    vi d(n+1,LLONG_MAX);
    // {距離,位置}
    priority_queue<pii,v<pii>,greater<>> pq;
    d[1]=0;
    pq.push({d[1],1});
    while (!pq.empty()) {
        auto[dist,pos]=pq.top();
        pq.pop();
        if (dist>d[pos]) continue;
        for (auto [nxt,w]:g[pos]) {
            if (chmin(d[nxt],dist+w)) pq.push({d[nxt],nxt});
        }
    }
    print(d[n]);

    return 0;
}

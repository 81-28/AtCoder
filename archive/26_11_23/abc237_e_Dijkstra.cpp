// https://atcoder.jp/contests/abc237/tasks/abc237_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi h(n);
    cin >> h;
    vvi g(n);
    while (m--) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        g[x].pb(y);
        g[y].pb(x);
    }
    // 全ての地点にH0-Hxがあるとして、
    // 下りを無料で、上りにコストがかかるようにして、損失を最小化
    vi d(n,-INF);
    // {スコア,位置}
    priority_queue<pii> q;
    d[0]=0;
    q.push({0,0});
    while (!q.empty()) {
        auto[c,pos]=q.top();
        q.pop();
        if (d[pos]>c) continue;
        for (int nxt:g[pos]) {
            if (chmax(d[nxt],c+min(0LL,h[pos]-h[nxt]))) q.push({d[nxt],nxt});
        }
    }
    int ans=0;
    rep(i,n) chmax(ans,d[i]+h[0]-h[i]);
    print(ans);

    return 0;
}

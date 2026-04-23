// https://atcoder.jp/contests/abc252/tasks/abc252_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // {都市,距離,番号}
    v<v<tuple<int,int,int>>> g(n);
    rep1(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        --a,--b;
        g[a].pb({b,c,i});
        g[b].pb({a,c,i});
    }
    // ある都市への最短経路を考えたとき、そこで通った都市も最短経路の道を通っている
    // 自分の都市に来る最短経路で最後に通った道(木になるので、1~n-1全てに親が存在し、その道の番号)
    vi p(n);
    vi d(n,INF);
    // {距離,位置}
    priority_queue<pii,v<pii>,greater<>> q;
    d[0]=0;
    q.push({d[0],0});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (d[pos]<dist) continue;
        for (auto[nxt,c,i]:g[pos]) {
            if (chmin(d[nxt],dist+c)) {
                q.push({d[nxt],nxt});
                p[nxt]=i;
            }
        }
    }
    rep1(i,n-1) cout<<p[i]<<' ';
    cout<<endl;

    return 0;
}

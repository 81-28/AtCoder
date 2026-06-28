// https://atcoder.jp/contests/abc211/tasks/abc211_d

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max();
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int mod=1e9+7;
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
    vi d(n,INF);
    vi ans(n,0);
    // {位置}
    queue<int> q;
    d[0]=0;
    ans[0]=1;
    q.push(0);
    vb b(n,0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        if (b[pos]) continue;
        b[pos]=1;
        for (int nxt:g[pos]) {
            chmin(d[nxt],d[pos]+1);
            if (d[nxt]<d[pos]+1) continue;
            ans[nxt]+=ans[pos];
            ans[nxt]%=mod;
            q.push(nxt);
        }
    }
    print(ans[n-1]);

    return 0;
}

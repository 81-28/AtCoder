// https://atcoder.jp/contests/abc209/tasks/abc209_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,t;
    cin >> n >> t;
    vvi g(n);
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi d(n,n);
    queue<int> q;
    d[0]=0;
    q.push(0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (chmin(d[nxt],d[pos]+1)) q.push(nxt);
        }
    }
    while (t--) {
        int a,b;
        cin >> a >> b;
        print((d[--b]-d[--a])&1?"Road ":"Town");
    }

    return 0;
}

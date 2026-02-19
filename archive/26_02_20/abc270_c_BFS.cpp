// https://atcoder.jp/contests/abc270/tasks/abc270_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=(int)v.size()-1;i>=0;--i)os<<v[i]<<(i?" ":"");return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,y;
    cin >> n >> x >> y;
    vvi g(n+1);
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi b(n+1,0);
    queue<int> q;
    b[x]=-1;
    q.push(x);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (b[nxt]) continue;
            b[nxt]=pos;
            q.push(nxt);
        }
    }
    vi ans;
    int now=y;
    while (now!=-1) {
        ans.pb(now);
        now=b[now];
    }
    print(ans);

    return 0;
}

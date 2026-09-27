// https://atcoder.jp/contests/abc168/tasks/abc168_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n);
    rep1(i,m) {
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
    vi ans(n,-1);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (chmin(d[nxt],d[pos]+1)) {
                q.push(nxt);
                ans[nxt]=pos;
            }
        }
    }
    bool ok=1;
    rep1(i,n-1) {
        if (ans[i]==-1) {
            ok=0;
            break;
        }
    }
    YesNo(ok);
    if (!ok) return 0;
    rep1(i,n-1) print(ans[i]+1);

    return 0;
}

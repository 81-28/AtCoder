// https://atcoder.jp/contests/adt_all_20260812_2/tasks/abc254_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    while (m--) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int t;
    cin >> t;
    vi d(n+1,n);
    queue<int> p,q;
    while (t--) {
        int x,k;
        cin >> x >> k;
        d[x]=0;
        q.push(x);
        int res=0;
        while (!q.empty()) {
            int pos=q.front();
            q.pop();
            res+=pos;
            p.push(pos);
            if (d[pos]>=k) continue;
            for (int nxt:g[pos]) {
                if (chmin(d[nxt],d[pos]+1)) q.push(nxt);
            }
        }
        print(res);
        while (!p.empty()) {
            d[p.front()]=n;
            p.pop();
        }
    }

    return 0;
}

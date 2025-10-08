// https://atcoder.jp/contests/abc299/tasks/abc299_e

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
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    // 0:白,1:黒
    vi c(n,1);
    // cnt:黒の数
    int cnt=n;
    int k;
    cin >> k;
    // b[i]:pに対して、これらのどれかが黒である必要がある
    vvi b(k);
    rep(i,k) {
        int p,d;
        cin >> p >> d;
        --p;
        vi dist(n,n*2);
        queue<int> q;
        dist[p]=0;
        q.push(p);
        while (!q.empty()) {
            int pos=q.front();
            q.pop();
            if (dist[pos]==d) b[i].pb(pos);
            else if (dist[pos]<d) {
                if (c[pos]) {
                    c[pos]=0;
                    --cnt;
                }
                for (int nxt:g[pos]) {
                    if (chmin(dist[nxt],dist[pos]+1)) q.push(nxt);
                }
            }
        }
    }
    if (cnt) {
        bool ok=1;
        for (vi vec:b) {
            bool bl=0;
            for(int val:vec) {
                if (c[val]) {
                    bl=1;
                    break;
                }
            }
            if (!bl) {
                ok=0;
                break;
            }
        }
        if (ok) {
            YesNo(1);
            for (int val:c) cout<<val;
            cout<<endl;
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

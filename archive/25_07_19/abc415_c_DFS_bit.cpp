// https://atcoder.jp/contests/abc415/tasks/abc415_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define YesNo(x) puts(x?"Yes":"No")


int mx;
vvi g;
v<bool> ok;
void dfs(int n) {
    for (int nxt:g[n]) {
        if (!ok[nxt]) {
            ok[nxt]=1;
            dfs(nxt);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        mx=s.size();
        // g[i]:状態iから行ける状態
        g=vvi(mx+1);
        ok=v<bool>(mx+1,0);
        rep1(i,mx) {
            if (s[i-1]=='1') continue;
            rep(j,n) {
                int m=(1<<j);
                int b=i/m%2;
                if (b) g[i-m].pb(i);
            }
        }
        ok[0]=1;
        dfs(0);
        YesNo(ok[mx]);
    }

    return 0;
}

// https://atcoder.jp/contests/abc315/tasks/abc315_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(n);
    rep(i,n) {
        int c;
        cin >> c;
        rep(j,c) {
            int p;
            cin >> p;
            --p;
            g[i].pb(p);
        }
    }
    // 使わない頂点からの入次数をカウントしないためにBFS
    // 使用する頂点
    v<bool> b(n,0);
    queue<int> q;
    b[0]=1;
    q.push(0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (!b[nxt]) {
                b[nxt]=1;
                q.push(nxt);
            }
        }
    }
    // 入次数
    vi cnt(n,0);
    rep(i,n) {
        for (int val:g[i]) {
            if (b[i]) ++cnt[val];
        }
    }
    vi ans;
    // queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        ans.pb(pos);
        for (int nxt:g[pos]) {
            --cnt[nxt];
            if (!cnt[nxt]) q.push(nxt);
        }
    }
    int m=ans.size();
    for (int i=m-1; i>0; --i) cout<<ans[i]+1<<' ';
    cout<<endl;

    return 0;
}

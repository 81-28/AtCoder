// https://atcoder.jp/contests/abc291/tasks/abc291_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // g[i]:iの位置の値より大きい数のidx
    vvi g(n);
    // 入次数
    vi cnt(n,0);
    while (m--) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        g[x].pb(y);
        ++cnt[y];
    }
    vi idx;
    queue<int> q;
    rep(i,n) {
        if (cnt[i]==0) q.push(i);
    }
    // トポロジカルソート
    // 並列に枝分かれするなら、一意ではない
    while (!q.empty()) {
        if (q.size()!=1) {
            YesNo(0);
            return 0;
        }
        int pos=q.front();
        q.pop();
        idx.pb(pos);
        for (int nxt:g[pos]) {
            --cnt[nxt];
            if (!cnt[nxt]) q.push(nxt);
        }
    }
    YesNo(1);
    vi ans(n);
    rep(i,n) ans[idx[i]]=i+1;
    print(ans);

    return 0;
}

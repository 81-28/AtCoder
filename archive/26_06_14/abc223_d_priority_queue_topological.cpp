// https://atcoder.jp/contests/abc223/tasks/abc223_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    // 自分より前に必要な個数
    vi cnt(n+1,0);
    while (m--) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        ++cnt[b];
    }
    priority_queue<int,vi,greater<>> q;
    rep1(i,n) {
        if (!cnt[i]) q.push(i);
    }
    vi ans;
    while (!q.empty()) {
        int num=q.top();
        q.pop();
        ans.pb(num);
        for (int nxt:g[num]) {
            if (!--cnt[nxt]) q.push(nxt);
        }
    }
    if (ans.size()==n) print(ans);
    else print(-1);

    return 0;
}

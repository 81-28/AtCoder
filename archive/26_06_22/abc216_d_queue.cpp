// https://atcoder.jp/contests/abc216/tasks/abc216_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    v<queue<int>> a(m);
    vi cnt(n,0);
    // 色iの位置
    vvi p(n);
    // 捨てる色
    queue<int> q;
    rep(i,m) {
        int k;
        cin >> k;
        rep(j,k) {
            int b;
            cin >> b;
            --b;
            a[i].push(b);
            p[b].pb(i);
        }
        int c=a[i].front();
        if (++cnt[c]==2) q.push(c);
    }
    int ans=n;
    while (!q.empty()) {
        int b=q.front();
        q.pop();
        --ans;
        for (int i:p[b]) {
            a[i].pop();
            if (a[i].empty()) continue;
            int c=a[i].front();
            if (++cnt[c]==2) q.push(c);
        }
    }
    YesNo(!ans);

    return 0;
}

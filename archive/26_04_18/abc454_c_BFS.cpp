// https://atcoder.jp/contests/abc454/tasks/abc454_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    vb c(n+1,0);
    rep1(i,m) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
    }
    queue<int> q;
    c[1]=1;
    q.push(1);
    while (!q.empty()) {
        int num=q.front();
        q.pop();
        for (int nxt:g[num]) {
            if (c[nxt]) continue;
            c[nxt]=1;
            q.push(nxt);
        }
    }
    int ans=0;
    rep1(i,n) ans+=c[i];
    print(ans);

    return 0;
}

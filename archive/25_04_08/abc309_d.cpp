// https://atcoder.jp/contests/abc309/tasks/abc309_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n1,n2,m;
    cin >> n1 >> n2 >> m;
    vvi g(n1+n2+1);
    int a,b;
    rep(i,m) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<int> q;
    vi dist(n1+n2+1,-1);
    v<bool> d(n1+n2+1,0);
    int mx1=0,mx2=0;
    d[1]=1;
    dist[1]=0;
    q.push(1);
    int now,nowd;
    while (!q.empty()) {
        now=q.front();
        q.pop();
        nowd=dist[now];
        for (int val:g[now]) {
            if (!d[val]) {
                d[val]=1;
                dist[val]=nowd+1;
                mx1=max(mx1,dist[val]);
                q.push(val);
            }
        }
    }
    d[n1+n2]=1;
    dist[n1+n2]=0;
    q.push(n1+n2);
    while (!q.empty()) {
        now=q.front();
        q.pop();
        nowd=dist[now];
        for (int val:g[now]) {
            if (!d[val]) {
                d[val]=1;
                dist[val]=nowd+1;
                mx2=max(mx2,dist[val]);
                q.push(val);
            }
        }
    }
    print(mx1+mx2+1);

    return 0;
}

// https://atcoder.jp/contests/abc304/tasks/abc304_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    double d;
    cin >> n >> d;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    vvi g(n);
    double dist;
    for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++) {
        dist=sqrt(pow(p[i].f-p[j].f,2)+pow(p[i].s-p[j].s,2));
        if (dist<=d) {
            g[i].pb(j);
            g[j].pb(i);
        }
    }
    v<bool> b(n,0);
    queue<int> q;
    b[0]=1;
    q.push(0);
    int pos;
    while (!q.empty()) {
        pos=q.front();
        q.pop();
        for (int val:g[pos]) {
            if (!b[val]) {
                b[val]=1;
                q.push(val);
            }
        }
    }
    rep(i,n)YesNo(b[i]);

    return 0;
}

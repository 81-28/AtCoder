// https://atcoder.jp/contests/abc345/tasks/abc345_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define YesNo(x) puts(x?"Yes":"No")

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}


int n,h,w;
v<pii> p;
v<bool> b;
bool dfs(const int& m,const v<v<bool>>& t) {
    if (m==h*w) return 1;
    int i=m/w,j=m%w;
    if (t[i][j]) return dfs(m+1,t);
    else {
        rep(k,n) {
            if (!b[k]) {
                v<pii> q;
                q.pb(p[k]);
                if (p[k].f!=p[k].s) q.pb({p[k].s,p[k].f});
                for (pii r:q) {
                    v<v<bool>> tt=t;
                    bool ok=1;
                    rep(x,r.f) {
                        if (i+x>=h) {
                            ok=0;
                            break;
                        }
                        rep(y,r.s) {
                            if (j+y>=w || tt[i+x][j+y]) {
                                ok=0;
                                break;
                            }
                            tt[i+x][j+y]=1;
                        }
                        if (!ok) break;
                    }
                    if (ok) {
                        b[k]=1;
                        if (dfs(m+1,tt)) return 1;
                        b[k]=0;
                    }
                }
            }
        }
        return 0;
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> h >> w;
    p=v<pii>(n);
    rep(i,n) cin >> p[i];
    b=v<bool>(n,0);
    YesNo(dfs(0,v<v<bool>>(h,v<bool>(w,0))));

    return 0;
}

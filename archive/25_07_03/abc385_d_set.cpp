// https://atcoder.jp/contests/abc385/tasks/abc385_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,x,y;
    cin >> n >> m >> x >> y;
    map<int,set<int>> r,c;
    rep(i,n) {
        pii p;
        cin >> p;
        r[p.s].insert(p.f);
        c[p.f].insert(p.s);
    }
    int ans=0;
    rep(i,m) {
        char d;
        int cnt;
        cin >> d >> cnt;
        if (d=='U') {
            int ny=y+cnt;
            auto it=c[x].lower_bound(y);
            while (it!=c[x].end()&&*it<=ny) {
                ++ans;
                r[*it].erase(x);
                it=c[x].erase(it);
            }
            y=ny;
        }
        if (d=='D') {
            int ny=y-cnt;
            auto it=c[x].lower_bound(ny);
            while (it!=c[x].end()&&*it<=y) {
                ++ans;
                r[*it].erase(x);
                it=c[x].erase(it);
            }
            y=ny;
        }
        if (d=='L') {
            int nx=x-cnt;
            auto it=r[y].lower_bound(nx);
            while (it!=r[y].end()&&*it<=x) {
                ++ans;
                c[*it].erase(y);
                it=r[y].erase(it);
            }
            x=nx;
        }
        if (d=='R') {
            int nx=x+cnt;
            auto it=r[y].lower_bound(x);
            while (it!=r[y].end()&&*it<=nx) {
                ++ans;
                c[*it].erase(y);
                it=r[y].erase(it);
            }
            x=nx;
        }
    }
    print(x,y,ans);

    return 0;
}

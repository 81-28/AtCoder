// https://atcoder.jp/contests/abc305/tasks/abc305_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()
template<class T>constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vvi g(n+1);
    rep(i,m) {
        pii p;
        cin >> p;
        g[p.f].pb(p.s);
        g[p.s].pb(p.f);
    }
    v<pii> p(k);
    rep(i,k) cin >> p[i].s >> p[i].f;
    sort(rall(p));
    vi d(n+1,-1);
    queue<int> q;
    for (auto [h,pos]:p) {
        if (chmax(d[pos],h)) q.push(pos);
        else continue;
        while (!q.empty()) {
            int now=q.front();
            q.pop();
            int nowd=d[now];
            for (int nxt:g[now]) {
                if (chmax(d[nxt],nowd-1)) {
                    q.push(nxt);
                }
            }
        }
    }
    vi ans;
    rep1(i,n) {
        if (d[i]!=-1) ans.pb(i);
    }
    print(ans.size());
    print(ans);

    return 0;
}

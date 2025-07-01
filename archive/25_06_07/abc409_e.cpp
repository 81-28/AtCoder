// https://atcoder.jp/contests/abc409/tasks/abc409_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vll x(n);
    cin >> x;
    map<pll,ll> cost;
    v<map<ll,bool>> g(n);
    vll cnt(n,0);
    rep(i,n-1) {
        pll p;
        ll w;
        cin >> p >> w;
        --p;
        g[p.f][p.s]=1;
        g[p.s][p.f]=1;
        ++cnt[p.f],++cnt[p.s];
        cost[p]=w;
    }
    queue<ll> q;
    rep(i,n) {
        if (cnt[i]==1) q.push(i);
    }
    v<bool> b(n,1);
    ll ans=0;
    while (!q.empty()) {
        ll pos=q.front();
        q.pop();
        b[pos]=0;
        ll nxt=-1;
        for (auto p:g[pos]) {
            if (b[p.f]) {
                nxt=p.f;
                break;
            }
        }
        if (nxt==-1) continue;
        pll p={min(pos,nxt),max(pos,nxt)};
        ans+=cost[p]*abs(x[pos]);
        x[nxt]+=x[pos];
        --cnt[nxt];
        if (cnt[nxt]==1) q.push(nxt);
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc303/tasks/abc303_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vvll g(n);
    pll p;
    rep(i,n-1) {
        cin >> p;
        --p.f,--p.s;
        g[p.f].pb(p.s);
        g[p.s].pb(p.f);
    }
    deque<ll> dq;
    v<bool> d(n,0);
    pll pos;
    queue<pll> q;
    ll idx;
    if (g[0].size()==1) q.push({g[0][0],0});
    else q.push({0,0});
    while (!q.empty()) {
        pos=q.front();
        q.pop();
        if (pos.s) dq.push_back(g[pos.f].size());
        else dq.push_front(g[pos.f].size());
        d[pos.f]=1;
        idx=0;
        for (ll val:g[pos.f]) {
            if (!d[val] && g[val].size()>1) {
                q.push({val,max(pos.s,idx)});
                ++idx;
            }
        }
    }
    vll ans;
    ans.pb(dq.front());
    dq.pop_front();
    while (!dq.empty()) {
        dq.pop_front();
        dq.pop_front();
        ans.pb(dq.front());
        dq.pop_front();
    }
    sort(all(ans));
    print(ans);

    return 0;
}

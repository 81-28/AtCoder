// https://atcoder.jp/contests/abc304/tasks/abc304_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll w,h,n;
    cin >> w >> h >> n;
    vll p(n),q(n);
    rep(i,n)cin >> p[i] >> q[i];
    ll a,b;
    cin >> a;
    vll x(a);
    cin >> x >> b;
    vll y(b);
    cin >> y;
    x.pb(w),y.pb(h);

    map<pll,ll> mp;
    ll c,d;
    ll mi=n,mx=0;
    rep(i,n) {
        c=*upper_bound(all(x),p[i]);
        d=*upper_bound(all(y),q[i]);
        mp[{c,d}]++;
        mx=max(mx,mp[{c,d}]);
    }
    if ((a+1)*(b+1)!=mp.size()) mi=0;
    else for(auto [k,val]:mp) mi=min(mi,val);
    print(mi,mx);

    return 0;
}

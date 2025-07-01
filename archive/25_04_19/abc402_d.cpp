// https://atcoder.jp/contests/abc402/tasks/abc402_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define f first
#define s second
using ll=long long;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    ll ans=0;
    map<ll,ll> mp;
    pll p;
    ll dist,deg;
    rep(i,m) {
        cin >> p;
        p.f--,p.s--;
        dist=min(p.f,n-p.s);
        p.f-=dist,p.s+=dist;
        p.s%=n;
        deg=p.f+p.s;
        ans+=i-mp[deg];
        mp[deg]++;
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc408/tasks/abc408_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<class T> constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vll sm(n+1,0);
    pll p;
    rep(i,m) {
        cin >> p;
        ++sm[p.f-1];
        --sm[p.s];
    }
    rep1(i,n) sm[i]+=sm[i-1];
    ll ans=n;
    rep(i,n) chmin(ans,sm[i]);
    print(ans);

    return 0;
}

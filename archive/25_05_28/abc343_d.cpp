// https://atcoder.jp/contests/abc343/tasks/abc343_d

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

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vll sc(n,0);
    unordered_map<ll,ll> cnt;
    cnt[0]=n;
    ll ans=1;
    pll p;
    rep(i,t) {
        cin >> p;
        --p.f;
        if (cnt[sc[p.f]]==1) --ans;
        --cnt[sc[p.f]];
        sc[p.f]+=p.s;
        ++cnt[sc[p.f]];
        if (cnt[sc[p.f]]==1) ++ans;
        print(ans);
    }

    return 0;
}

// https://atcoder.jp/contests/abc409/tasks/abc409_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,l;
    cin >> n >> l;
    if (l%3) {
        print(0);
        return 0;
    }
    ll e=l/3;
    vll cnt(l,0);
    ++cnt[0];
    vll d(n,0);
    rep1(i,n-1) {
        cin >> d[i];
        d[i]+=d[i-1];
        d[i]%=l;
        ++cnt[d[i]];
    }
    ll ans=0;
    rep(i,e) {
        ans+=cnt[i]*cnt[i+e]*cnt[i+e*2];
    }
    print(ans);

    return 0;
}

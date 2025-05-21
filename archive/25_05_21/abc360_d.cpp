// https://atcoder.jp/contests/abc360/tasks/abc360_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,t;
    string s;
    cin >> n >> t >> s;
    vll x(n);
    cin >> x;
    vll l,r;
    rep(i,n) {
        if (s[i]=='0') l.pb(x[i]);
        else r.pb(x[i]);
    }
    sort(all(l));
    sort(all(r));
    ll ans=0;
    for (ll val:r) {
        auto itl=lower_bound(all(l),val);
        auto itr=upper_bound(all(l),val+t*2);
        ans+=(itr-itl);
    }
    print(ans);


    return 0;
}

// https://atcoder.jp/contests/abc403/tasks/abc403_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


ll f(const vll& vec) {
    ll n=vec.size();
    // dp[i][j]:i番の要素を消すかどうか(j)での最小値
    vvll dp(n,vll(2));
    dp[0][0]=0,dp[0][1]=vec[0];
    for (ll i=1; i<n; i++) {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+vec[i];
    }
    return min(dp[n-1][0],dp[n-1][1]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,d;
    cin >> n >> d;
    vll a(n);
    cin >> a;
    unordered_map<ll,ll> c;
    set<ll> s;
    rep(i,n) {
        c[a[i]]++;
        s.insert(a[i]);
    }
    if (d==0) {
        print(n-s.size());
        return 0;
    }

    ll ans=0;
    ll mx=*s.rbegin();
    vll u;
    rep(i,d) {
        u=vll();
        for (ll j=i; j<=mx; j+=d) {
            u.pb(c[j]);
        }
        if (u.size()) ans+=f(u);
    }
    print(ans);

    return 0;
}

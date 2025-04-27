// https://atcoder.jp/contests/abc403/tasks/abc403_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define YesNo(x) puts(x?"Yes":"No")
// #define f first
// #define s second
using ll=long long;
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// using mint=modint1000000007;
// using mint=modint998244353;

// inもoutもAtCoderではvectorとpair組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}

ll f(const vll& vec) {
    ll n=vec.size();
    // dp[i][j]:i番の要素を消すかどうか(j)での最小値
    vvll dp(n,vll(2,LLONG_MAX));
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
    unordered_map<ll,ll> m;
    set<ll> s;
    rep(i,n) {
        m[a[i]]++;
        s.insert(a[i]);
    }
    if (d==0) {
        print(n-s.size());
        return 0;
    }

    vvll g;
    vll u;
    ll mx=*s.rbegin(),mi=*s.begin();
    for (auto it=s.begin(); *it < mi+d; it++) {
        u=vll();
        for (ll i=*it; i<=mx; i+=d) {
            if (m[i]) {
                u.pb(m[i]);
            } else {
                if (u.size()>0) g.pb(u);
                u=vll();
            }
        }
        if (u.size()>0) g.pb(u);
    }

    ll ans=0;
    for (vll vec:g) ans+=f(vec);
    print(ans);

    return 0;
}

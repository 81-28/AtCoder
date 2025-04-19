// https://atcoder.jp/contests/abc402/tasks/abc402_f

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


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vvll a(n,vll(n));
    cin >> a;
    ll ten=1;
    for (ll j=n-1; j>=0; j--) {
        for (ll x=n-1,y=j; y<n; x--,y++) {
            a[x][y]=(a[x][y]*ten)%m;
        }
        ten=(ten*10)%m;
    }
    for (ll i=n-2; i>=0; i--) {
        for (ll x=i,y=0; x>=0; x--,y++) {
            a[x][y]=(a[x][y]*ten)%m;
        }
        ten=(ten*10)%m;
    }
    // rep(i,n)print(a[i]);
    v<v<unordered_set<ll>>> dp(n,v<unordered_set<ll>>(n));
    dp[0][0].insert(a[0][0]);
    for (ll i=1; i<n; i++) {
        dp[i][0].insert((*dp[i-1][0].begin()+a[i][0])%m);
        dp[0][i].insert((*dp[0][i-1].begin()+a[0][i])%m);
    }
    for(ll i=1; i<n; i++)for(ll j=1; j<n; j++) {
        for (ll val:dp[i-1][j]) {
            dp[i][j].insert((val+a[i][j])%m);
        }
        for (ll val:dp[i][j-1]) {
            dp[i][j].insert((val+a[i][j])%m);
        }
    }
    ll ans=0;
    for (ll val:dp[n-1][n-1]) ans=max(ans,val);
    print(ans);


    return 0;
}

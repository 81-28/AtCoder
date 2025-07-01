// https://atcoder.jp/contests/abc390/tasks/abc390_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
// #define f first
// #define s second
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
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

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
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
// #define max(...) (*max_element({__VA_ARGS__}))
// #define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,x;
    cin >> n >> x;
    ll vit,a,c;
    v<v<pll>> vec(3);
    rep(i,n) {
        cin >> vit >> a >> c;
        vec[vit-1].pb({c,a});
    }
    rep(i,3) sort(all(vec[i]));
    // 最初のi個まで(のうちいくつか選んで)でj以下のカロリーで可能な最大ビタミン
    v<v<map<ll,ll>>> dp(3);
    v<map<ll,ll>> DP(3);
    rep(k,3) {
        int s=vec[k].size();
        dp[k] = v<map<ll,ll>>(s+1);
        dp[k][0][0] = 0;
        rep(i,s) {
            // rep(j,x) {
            for(pll p:dp[k][i]) {
                ll cost = vec[k][i].first;
                if (p.first + cost <= x) {
                    dp[k][i+1][p.first+cost] = dp[k][i][p.first] + vec[k][i].second;
                } else {
                    dp[k][i+1][p.first] = max(dp[k][i+1][p.first],dp[k][i][p.first]);
                }
            }
        }
        DP[k] = dp[k][s];
    }
    ll ans = 0;
    for(pll p:DP[0])for(pll q:DP[1])for(pll r:DP[2]) {
        ll i=p.first, j=q.first, k=r.first;
    // rep1(i,x)rep1(j,x)rep1(k,x) {
        if (i+j+k > x) break;
        ans = max(ans,min({DP[0][i],DP[1][j],DP[2][k]}));
    }
    // rep(i,3) print(DP[i]);
    print(ans);

    return 0;
}

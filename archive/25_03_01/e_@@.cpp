// https://atcoder.jp/contests/abc395/tasks/abc395_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define f first
#define s second
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

    ll n,m,x;
    cin >> n >> m >> x;
    x++;
    ll a,b;
    v<v<pll>> g(n+1);
    rep(i,m) {
        cin >> a >> b;
        g[a].pb({b,0});
        g[a].pb({b,1});
    }
    v<pll> ans(n+1,{LLONG_MAX,0});
    ans[1]={0,0};
    queue<ll> q;
    q.push(1);
    ll now;
    int bit;
    while (!q.empty()) {
        now=q.front();
        q.pop();
        bit=ans[now].s;
        for (pll p:g[now]) {
            if (bit^p.s) {
                if (ans[p.f].f > ans[now].f + x) {
                    ans[p.f] = {ans[now].f + x,1};
                    q.push(p.f);
                }
            } else {
                if (ans[p.f].f > ans[now].f + 1) {
                    q.push(p.f);
                }
            }
            
            
        }
        
    }
    

    return 0;
}

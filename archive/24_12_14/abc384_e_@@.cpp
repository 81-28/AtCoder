// https://atcoder.jp/contests/abc384/tasks/abc384_e

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
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
#define max(...) (*max_element({__VA_ARGS__}))
#define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,p,q;
    ll x;
    cin >> h >> w >> x >> p >> q;
    p--,q--;
    vvll s(h,vll(w));
    rep(i,h) cin >> s[i];
    vvi d(h,vi(w,0));

    ll ans = s[p][q];
    ll pans;
    d[p][q] = 1;

    unordered_set<int> se;
    vi e;
    int i,j;
    if (0 <= p-1) se.insert((p-1)*w+q);
    if (p+1 < h) se.insert((p+1)*w+q);
    if (0 <= q-1) se.insert(p*w+(q-1));
    if (q+1 < w) se.insert(p*w+(q+1));
    while(!se.empty()) {
        pans = ans;
        e = vi(0);
        for(auto val:se) {
            i = val/w, j = val%w;
            if (s[i][j]*x < ans) {
                ans += s[i][j];
                d[i][j] = 1;
                e.pb(val);
                if (0 <= i-1 && !d[i-1][j]) se.insert((i-1)*w+j);
                if (i+1 < h && !d[i+1][j]) se.insert((i+1)*w+j);
                if (0 <= j-1 && !d[i][j-1]) se.insert(i*w+(j-1));
                if (j+1 < w && !d[i][j+1]) se.insert(i*w+(j+1));
            }
        }
        for(auto val:e) se.erase(val);
        if (pans == ans) break;
    }
    print(ans);

    return 0;
}

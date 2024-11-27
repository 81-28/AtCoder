// https://atcoder.jp/contests/abc381/tasks/abc381_d

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


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,ans=0;
    cin >> n;
    vi a(n);
    cin >> a;
    int combo=1;
    v<pii> b;
    for (int i=1; i<n; i++) {
        if (a[i-1]==a[i]) {
            combo++;
        } else {
            b.pb({combo,a[i-1]});
            combo=1;
        }
    }
    b.pb({combo,a[n-1]});
    int bn = b.size();
    vi c;
    set<int> s;
    int newc;
    rep(i,bn) {
        if (b[i].first >= 2) {
            newc = b[i].second;
            while(s.find(newc) != s.end()) {
                s.erase(*c.begin());
                c.erase(c.begin());
            }
            c.pb(newc);
            s.insert(newc);
            ans = max(ans,(int)c.size());
        } else {
            c = vi(0);
            s = set<int>();
        }
    }
    print(ans*2);


    return 0;
}

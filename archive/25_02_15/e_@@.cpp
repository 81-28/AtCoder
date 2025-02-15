// https://atcoder.jp/contests/abc393/tasks/abc393_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
// #define f first
// #define s second
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
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


// 素数判定する関数
bool isPrime(const int& n) {
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (!(n%2&&n%3)) return false;
    for (int i=5;i*i<=n;i+=6) if (!(n%i&&n%(i+2))) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    vll a(n);
    cin >> a;
    ll m=max(a);
    vll d(m+1,0);
    d[1]=n;
    ll b;
    rep(i,n) {
        b=a[i];
        if (b < 2 || isPrime(b)) {
            d[b]++;
        } else {
            ll divisor = 2;
            while (b >= 2) {
                if (b % divisor == 0) {
                    d[b]++;
                    b /= divisor;
                } else {
                    divisor++;
                }
            }
        }
    }
    vll factors;
    rep(i,n) {
        factors.clear();
        b=a[i];
        if (b < 2 || isPrime(b)) {
            factors.push_back(b);
        } else {
            ll divisor = 2;
            while (b >= 2) {
                if (b % divisor == 0) {
                    factors.push_back(divisor);
                    b /= divisor;
                } else {
                    divisor++;
                }
            }
        }
        sort(rall(factors));
        for(ll val:factors) {
            if (d[val] >= k) {
                print(val);
                break;
            }
        }
    }
    print(d);

    return 0;
}

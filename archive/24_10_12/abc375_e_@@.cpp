// https://atcoder.jp/contests/abc375/tasks/abc375_e

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
#define rep2(i,s,n) for (int i=(int)(s); i<(int)(n); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define YesNo(x) cout<<(x ? "Yes\n":"No\n")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;
using vll = v<ll>;
using vvll = v<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
// using mint = modint1000000007;
// using mint = modint998244353;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

template<typename T>
int sum(const vector<T>& v) { return accumulate(v.begin(),v.end(),0); }
template<typename T>
ll sumLL(const vector<T>& v) { return accumulate(v.begin(),v.end(),0LL); }

template<typename T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }
template<typename T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
template<typename T, typename... Args>
T max(const T& a, const T& b, const T& c, const Args&... args) { return max({a,b,c,args...}); }
template<typename T, typename... Args>
T min(const T& a, const T& b, const T& c, const Args&... args) { return min({a,b,c,args...}); }


int main() {
    fastio();

    int n;
    cin >> n;
    vvi t(3);
    int a;
    vi b(n);
    rep(i,n) {
        cin >> a >> b[i];
        t[a-1].pb(b[i]);
    }
    vi s(3);
    rep(i,3) s[i] = sum(t[i]);
    if (s[0] == s[1] && s[1] == s[2]) print(0);
    else {
        int ss = sum(s);
        if (ss%3 != 0) print(0);
        else {
            int ave = ss/3;
            v<v<bool>> dp(n+1,v<bool>(ss+1,false));
            rep1(i,n) {
                rep1(j,ss) {
                    if ((dp[i-1][j]) || (j-b[i-1] >= 0 && dp[i-1][j-b[i-1]])) dp[i][j] = true;
                }
            }
            if (dp[n][ave] && dp[n][ave*2]) {
                // 
            } else print(-1);
        }
    }

    return 0;
}

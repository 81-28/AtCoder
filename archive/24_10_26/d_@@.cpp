// https://atcoder.jp/contests/abc377/tasks/abc377_d

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

    int n,m;
    cin >> n >> m;
    // vi l(n),r(n);
    // rep(i,n) cin >> l[i] >> r[i];
    set<pii> p;
    p.insert({1,m});
    int len;
    int l,r;
    auto itP = p.begin();
    pii nowP;
    rep(i,n) {
        cin >> l >> r;
        len = p.size();
        for (int j = len-1; j >= 0; j--) {
            itP = p.begin();
            advance(itP,j);
            nowP = *itP;
            if (nowP.first <= l && r <= nowP.second) {
                p.erase(itP);
                if (r >= 2 && r <= nowP.second) p.insert({nowP.first,r-1});
                if (l <= m-1 && nowP.first <= l) p.insert({l+1,nowP.second});
            }
        }
    }
    ll ans = 0;
    len = p.size();
    int a,b;
    int last = 0;
    // v<pii> d(all(p));
    // rep(i,len) print(d[i].first,d[i].second);

    // set<pii> c;

    rep(k,len) {
        itP = p.begin();
        advance(itP,k);
        nowP = *itP;
        // for (int i = nowP.first; i <= nowP.second; i++) {
        //     for (int j = i; j <= nowP.second; j++) c.insert({i,j});
        // }
        a = nowP.second - nowP.first +1;
        if (a >= 1) ans += a;
        if (a >= 2) ans += (a*(a-1)/2);
        // 重複部分を削る
        if (last) {
            b = last - nowP.first +1;
            if (b >= 1) ans -= b;
            if (b >= 2) ans -= (b*(b-1)/2);
        }
        last = nowP.second;
    }
    print(ans);
    // print(c.size());

    return 0;
}

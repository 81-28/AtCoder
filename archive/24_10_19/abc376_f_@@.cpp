// https://atcoder.jp/contests/abc376/tasks/abc376_f

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

    int n,q;
    cin >> n >> q;
    int ans = 0;
    v<char> h(q);
    vi t(q);
    int l = 1, r = 2;
    int add;
    vi vl,vr;
    rep(i,q) {
        cin >> h[i] >> t[i];
        if (h[i] == 'L') vl.pb(i);
        else vr.pb(i);
    }
    int inL = 0,inR = 0;
    rep(i,q) {
        add = n;
        if (h[i] == 'L') {
            if ((l < t[i] && t[i] < r) || (r < l && l < t[i]) || (t[i] < r && r < l)) {
                if (add > (t[i]+n-l)%n) {
                    add = (t[i]+n-l)%n;
                }
                if (add > ((l+n-t[i])%n)+((r+n-(t[i]-1))%n)+((vr[inR]+n-(t[i]-1))%n)) {
                    add = ((l+n-t[i])%n)+((r+n-(t[i]-1))%n);
                    r = t[i]-1;
                }
            } else {
                if (add > (l+n-t[i])%n && t[i] != r) {
                    add = (l+n-t[i])%n;
                }
                if (add > ((t[i]+n-l)%n)+((t[i]+1+n-r)%n)+(((t[i]+1)+n-vr[inR])%n)) {
                    add = ((t[i]+n-l)%n)+((t[i]+1+n-r)%n);
                    r = t[i]+1;
                }
            }
            l = t[i];
            inL++;
        }
        if (h[i] == 'R') {
            if ((r < t[i] && t[i] < l) || (l < r && r < t[i]) || (t[i] < l && l < r)) {
                if (add > (t[i]+n-r)%n) {
                    add = (t[i]+n-r)%n;
                }
                if (add > ((r+n-t[i])%n)+((l+n-(t[i]-1))%n)+((vl[inL]+n-(t[i]-1))%n)) {
                    add = ((r+n-t[i])%n)+((l+n-(t[i]-1))%n);
                    l = t[i]-1;
                }
            } else {
                if (add > (r+n-t[i])%n && t[i] != l) {
                    add = (r+n-t[i])%n;
                }
                if (add > ((t[i]+n-r)%n)+((t[i]+1+n-l)%n)+(((t[i]+1)+n-vl[inL])%n)) {
                    add = ((t[i]+n-r)%n)+((t[i]+1+n-l)%n);
                    l = t[i]+1;
                }
            }
            r = t[i];
            inR++;
        }
        ans += add;
    }
    print(ans);

    return 0;
}

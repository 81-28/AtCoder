// https://atcoder.jp/contests/abc370/tasks/abc370_d

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
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

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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

    ll h,w;
    int q;
    cin >> h >> w >> q;
    ll ans = h*w;
    v<v<bool>> a(h,v<bool>(w,true));
    v<set<int>> row;
    rep(i,h) {
        rep(j,w) row[i].insert(j);
    }
    rep(k,q) {
        int r,c;
        cin >> r >> c;
        r--;
        c--;
        if (a[r][c]) {
            a[r][c] = false;
            row[r].erase(c);
            ans--;
        } else {
            for (int i = r-1; i >= 0; i--) {
                if (a[i][c]) {
                    a[i][c] = false;
                    row[i].erase(c);
                    ans--;
                    break;
                }
            }
            for (int i = r+1; i < h; i++) {
                if (a[i][c]) {
                    a[i][c] = false;
                    row[i].erase(c);
                    ans--;
                    break;
                }
            }
            auto autoC = row[r].lower_bound(c);
            if (autoC != row[r].end()) {
                a[r][*autoC] = false;
                row[r].erase(*autoC);
                ans--;
            }
            autoC = row[r].lower_bound(c);
            autoC--;
            if (autoC != row[r].begin()) {
                a[r][*autoC] = false;
                row[r].erase(*autoC);
                ans--;
                ans--;
            }
        }
    }
    print(ans);

    return 0;
}

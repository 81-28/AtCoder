// https://atcoder.jp/contests/abc369/tasks/abc369_d

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

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

int sum(const vector<int>& v) { return accumulate(all(v),0); }
ll sumLL(const vector<int>& v) { return accumulate(all(v),0LL); }
int sum(const set<int>& set) {
    vector<int> vec(all(set));
    return accumulate(all(vec),0);
}
ll sumLL(const set<int>& set) {
    vector<int> vec(all(set));
    return accumulate(all(vec),0LL);
}


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<ll> dp(n,0LL);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (j == i) {
                if ((j+1)%2 == 0)
                    dp[j] = dp[j-1] + a[j]*2;
                else
                    dp[j] = dp[j-1] + a[j];
            } else if (j == 0) {
                dp[0] = max(dp[0],a[i]);
            } else {
                if ((j+1)%2 == 0)
                    dp[j] = max(dp[j], dp[j-1] + a[i]*2);
                else
                    dp[j] = max(dp[j], dp[j-1] + a[i]);
            }
        }
    }
    ll ans = 0;
    rep(j,n) ans = max(ans, dp[j]);
    print(ans);

    return 0;
}

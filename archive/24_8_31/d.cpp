// https://atcoder.jp/contests/abc369/tasks/abc369_d

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    // dp[i][j] : 最初のi+1匹中j+1匹倒して得られる最大経験値
    vector<vector<ll>> dp(n,vector<ll>(n,0LL));
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], a[i]);
    }
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            if (i == j) {
                if ((j+1)%2 == 0)
                    dp[i][j] = dp[i-1][j-1] + a[i]*2;
                else
                    dp[i][j] = dp[i-1][j-1] + a[i];
            } else {
                if ((j+1)%2 == 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i]*2);
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i]);
            }
        }
    }
    ll ans = 0;
    rep(j,n) ans = max(ans, dp[n-1][j]);
    print(ans);

    return 0;
}

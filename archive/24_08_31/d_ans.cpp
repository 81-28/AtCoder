// https://atcoder.jp/contests/abc369/tasks/abc369_d

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
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
    // dp[i][j] : (i+1)倍経験値が入る状態でj+1匹目の後の最大経験値
    vector<vector<ll>> dp(2,vector<ll>(n+1,LLONG_MIN));
    dp[0][0] = 0;
    rep1(j,n) {
        rep(i,2) {
            // 倒さない(値を維持)
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
            // 倒す(値を加算)
            dp[!i][j] = max(dp[!i][j],dp[i][j-1] + a[j-1]*(i+1));
        }
    }
    print(max(dp[0][n],dp[1][n]));

    return 0;
}

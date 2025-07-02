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
    // dp[i][j] : 状態iでj+1匹目を倒して得られる最大経験値
    // 状態i= 0:奇数番目に倒さない場合, 1:奇数番目に倒す場合,
    // 　　   2:偶数番目に倒さない場合, 3:偶数番目に倒す場合
    vector<vector<ll>> dp(4,vector<ll>(n,LLONG_MIN));
    dp[0][0] = 0;
    dp[1][0] = a[0];
    // dp[2][0],dp[3][0]は到達不可能
    for (int j = 1; j < n; j++) {
        dp[0][j] = max(dp[0][j-1],dp[3][j-1]);
        dp[1][j] = dp[0][j] + a[j];
        dp[2][j] = max(dp[1][j-1],dp[2][j-1]);
        dp[3][j] = dp[2][j] + a[j]*2;
    }
    print(max(dp[1][n-1],dp[3][n-1]));

    return 0;
}

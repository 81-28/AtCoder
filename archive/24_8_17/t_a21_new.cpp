// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_u

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)

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
    vector<int> p(n+1),a(n+1);
    rep1(i,n) {
        cin >> p[i] >> a[i];
    }
    // 三角のdp
    // dp[i][j] : 左からi,右からj削ったときの最大スコア
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // このやり方では、2つの子の最高スコアを更新している
    rep(i,n) {
        rep(j,n-i) {
            int ni = i+1,nj = j+1;
            if (ni < p[ni] && p[ni] < n+1-j) {
                dp[ni][j] = max(dp[ni][j],dp[i][j] + a[ni]);
            } else {
                dp[ni][j] = max(dp[ni][j],dp[i][j]);
            }
            if (i < p[n+1-nj] && p[n+1-nj] < n+1-nj) {
                dp[i][nj] = max(dp[i][nj],dp[i][j] + a[n+1-nj]);
            } else {
                dp[i][nj] = max(dp[i][nj],dp[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans,dp[i][n-i]);
    }
    print(ans);

    return 0;
}

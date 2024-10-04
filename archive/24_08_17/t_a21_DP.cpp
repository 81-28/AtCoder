// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_u

#include <bits/stdc++.h>
using namespace std;

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
    // このやり方では、2つの親を比べて現在の最高スコアを算出している
    int ans = 0;
    rep1(i,n) {
        if (i < p[i]) {
            dp[i][0] = dp[i-1][0] + a[i];
        } else {
            dp[i][0] = dp[i-1][0];
        }
    }
    ans = max(ans,dp[n][0]);
    rep1(j,n) {
        if (n+1-j > p[n+1-j]) {
            dp[0][j] = dp[0][j-1] + a[n+1-j];
        } else {
            dp[0][j] = dp[0][j-1];
        }
    }
    ans = max(ans,dp[0][n]);
    for (int i = 1; i <= n-1; i++) {
        for (int j = 1; j <= n-i; j++) {
            int la = 0,ra = 0;
            if (i < p[i] && p[i] < n+1-j) {
                la = a[i];
            }
            if (i < p[n+1-j] && p[n+1-j] < n+1-j) {
                ra = a[n+1-j];
            }
            dp[i][j] = max(dp[i-1][j]+la,dp[i][j-1]+ra);
        }
        ans = max(ans,dp[i][n-i]);
    }
    print(ans);

    return 0;
}

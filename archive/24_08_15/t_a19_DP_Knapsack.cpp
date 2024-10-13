// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_s

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
template<typename T>
using v = vector<T>;
using vll = v<ll>;
using vvll = v<vll>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    fastio();

    int n,wt;
    cin >> n >> wt;
    vll w(n+1),v(n+1);
    rep1(i,n) cin >> w[i] >> v[i];

    // dp[i][j] : 最初のi個まで(のうち何個か選んで)で重さj以下での最高スコアの表
    vvll dp(n+1,vll(wt+1,0LL));
    rep1(i,n) {
        rep1(j,wt) {
            if (j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    print(dp[n][wt]);

    return 0;
}

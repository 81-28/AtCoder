// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bw

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;
using pii = pair<int,int>;

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

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i].second >> p[i].first;
    sort(all(p));

    // dp[i][j] : 最初のi問までで、j分までに答えられる最大問数
    vvi dp(n+1,vi(1441,0));
    rep(i,n) {
        rep1(j,1440) {
            dp[i+1][j] = dp[i][j];
            if (j <= p[i].first && (j-p[i].second) >= 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j-p[i].second]+1);
        }
    }
    int ans = 0;
    rep1(j,1440) ans = max(ans,dp[n][j]);
    print(ans);

    return 0;
}

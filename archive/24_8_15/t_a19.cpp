// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_s

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
    int n,wt;
    cin >> n >> wt;
    vector<ll> w(n+1),v(n+1);
    rep1(i,n) {
        cin >> w[i] >> v[i];
    }

    // dp[i][j] : 最初のi個まで(のうち何個か選んで)で重さj以下での最高スコアの表
    vector<vector<ll>> dp(n+1,vector<ll>(wt+1,0LL));
    rep1(i,n) {
        for (int j = 0; j <= wt; j++)
        {
            if (j < w[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= wt; i++)
    {
        ans = max(ans,dp[n][i]);
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cr

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
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

template<typename T>
int sum(const vector<T>& v) { return accumulate(v.begin(),v.end(),0); }


int main() {
    fastio();

    int n,wt;
    cin >> n >> wt;
    vll w(n+1),v(n+1,0);
    rep1(i,n) cin >> w[i] >> v[i];
    int sv = sum(v);

    // dp[i][j] : 最初のi個まで(のうち何個か選んで)で価値jにするための最小コスト(重さ)の表
    vvll dp(n+1,vll(sv+1,LLONG_MAX-1e10));
    dp[0][0] = 0LL;
    rep1(i,n) {
        rep(j,sv+1) {
            if (j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    ll ans = 0;
    for (int j = sv; j > 0; j--) {
        if (dp[n][j] <= wt) {
            ans = j;
            break;
        }
    }
    print(ans);

    return 0;
}

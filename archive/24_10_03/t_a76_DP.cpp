// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bx

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
using ll = long long;
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vll = v<ll>;
const ll mod = 1e9+7;

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

    int n,w,l,r;
    cin >> n >> w >> l >> r;
    vi x(n+2);
    x[0] = 0;
    rep1(i,n) {
        cin >> x[i];
    }
    x[n+1] = w;
    // dp[i]: 足場iにいる方法の通り数, sum[i]: 足場0からiまでのすべtの到達方法の合計
    vll dp(n+2,0LL), sum(n+2,0LL);
    dp[0] = 1;
    sum[0] = 1;
    rep1(i,n+1) {
        int posL = lower_bound(all(x),x[i]-r) - x.begin();
        int posR = upper_bound(all(x),x[i]-l) - x.begin()-1;
        if (0 <= posR) dp[i] = sum[posR];
        if (0 < posL) dp[i] = (dp[i] - sum[posL-1] + mod) % mod;

        sum[i] = (sum[i-1] + dp[i]) % mod;
    }
    print(dp[n+1]);

    return 0;
}

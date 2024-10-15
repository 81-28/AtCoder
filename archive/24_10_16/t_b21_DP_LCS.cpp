// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ct

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

template<typename T, typename... Args>
T max(const T& a, const T& b, const T& c, const Args&... args) { return max({a,b,c,args...}); }


int main() {
    fastio();

    int n;
    string s,t;
    cin >> n >> s;
    t = s;
    reverse(all(t));

    vvi dp(n+1,vi(n+1,0));
    rep1(i,n) rep1(j,n) {
        if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+1);
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
    print(dp[n][n]);

    return 0;
}

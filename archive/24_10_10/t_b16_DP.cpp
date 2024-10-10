// https://atcoder.jp/contests/tessoku-book/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

#define rep2(i,s,n) for (int i=(int)(s); i<(int)(n); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
    fastio();

    int n;
    cin >> n;
    vi h(n);
    cin >> h;
    // dp[i] : 足場iに来る方法の最小コスト
    vi dp(n);
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    rep2(i,2,n) {
        dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));
    }
    print(dp[n-1]);

    return 0;
}

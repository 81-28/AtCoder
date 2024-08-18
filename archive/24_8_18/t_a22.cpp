// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_v

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    vector<int> a(n-1),b(n-1);
    cin >> a >> b;
    // 0で初期化すると到達できないマスも選択肢に入ってしまう。
    vector<int> dp(n,INT_MIN);
    dp[0] = 0;
    rep(i,n-1) {
        dp[a[i]-1] = max(dp[a[i]-1],dp[i]+100);
        dp[b[i]-1] = max(dp[b[i]-1],dp[i]+150);
    }
    print(dp[n-1]);

    return 0;
}

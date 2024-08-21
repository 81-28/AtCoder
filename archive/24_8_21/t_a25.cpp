// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_y

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    cin >> c;
    // dp[i][j] : マスi,jにいく方法の数
    vector<vector<ll>> dp(h,vector<ll>(w,0));
    dp[0][0] = 1;
    rep(i,h) {
        rep(j,w) {
            if (dp[i][j] != 0) {
                // 右
                if (j < w-1 && c[i][j+1] == '.') {
                    dp[i][j+1] += dp[i][j];
                }
                // 下
                if (i < h-1 && c[i+1][j] == '.') {
                    dp[i+1][j] += dp[i][j];
                }
            }
        }
    }
    print(dp[h-1][w-1]);

    return 0;
}

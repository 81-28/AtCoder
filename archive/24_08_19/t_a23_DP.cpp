// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_w

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>(n));
    rep(i,m) cin >> a[i];
    // dp[i][j] : 最初のi枚まで(のうち何枚か選んで)で状態jを作るのに必要な最小枚数
    // 子を更新するdp
    vector<vector<int>> dp(m+1,vector<int>((1<<n),INT_MAX));
    dp[0][0] = 0;
    rep(i,m) {
        rep(j,(1<<n)) {
            if (dp[i][j] != INT_MAX) {
                // i+1枚目を選ばない場合
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
                // i+1枚目を選ぶ場合
                int newJ = 0;
                rep(k,n) {
                    if (j/(1<<k)%2 == 1 || a[i][k] == 1) newJ += (1<<(k));
                }
                dp[i+1][newJ] = min(dp[i+1][newJ],dp[i][j]+1);
            }
        }
    }
    if (dp[m][(1<<n)-1] == INT_MAX) print(-1);
    else print(dp[m][(1<<n)-1]);

    return 0;
}

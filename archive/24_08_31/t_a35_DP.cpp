// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ai

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
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[n-1] = a;
    for (int i = n-2; i >= 0; i--) {
      rep(j,i+1) {
            if(i%2) dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]);
            else dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    print(dp[0][0]);

    return 0;
}
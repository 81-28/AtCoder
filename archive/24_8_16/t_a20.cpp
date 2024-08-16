// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_t

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    string s,t;
    cin >> s >> t;
    int sn = s.size(),tn = t.size();
    // dp[i][j] : sのi文字目,tのj文字目までで最大の部分列の長さ
    vector<vector<int>> dp(sn+1,vector<int>(tn+1,0));
    rep1(i,sn) {
        rep1(j,tn) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+1});
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    print(dp[sn][tn]);

    return 0;
}

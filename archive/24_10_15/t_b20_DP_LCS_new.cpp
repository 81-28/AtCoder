// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cs

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
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
T min(const T& a, const T& b, const T& c, const Args&... args) { return min({a,b,c,args...}); }


int main() {
    fastio();

    string s,t;
    cin >> s >> t;
    int sn = s.size(),tn = t.size();
    // dp[i][j] : sのi文字目まで を、tのj文字目まで にする最小スコア
    vvi dp(sn+1,vi(tn+1,0));
    rep1(i,sn) dp[i][0] = i;
    rep1(j,tn) dp[0][j] = j;

    rep1(i,sn) rep1(j,tn) {
        // 消す/足す/変更
        dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
        // 同じ文字なら操作なし
        if (s[i-1] == t[j-1]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
    }
    print(dp[sn][tn]);

    return 0;
}

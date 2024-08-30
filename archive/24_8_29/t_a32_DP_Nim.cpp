// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_af

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
    int n,a,b;
    cin >> n >> a >> b;
    // dp[i] : 石がi個残ってる状態で先手(今の手番)が勝つかどうか
    vector<bool> dp(n+1);
    dp[0] = false;
    rep1(i,n) {
        // 相手に勝ちを譲らないように行動する
        if (i-a >= 0 && dp[i-a] == false) dp[i] = true;
        else if (i-b >= 0 && dp[i-b] == false) dp[i] = true;
        else dp[i] = false;
    }

    if (dp[n]) print("First");
    else print("Second");

    return 0;
}

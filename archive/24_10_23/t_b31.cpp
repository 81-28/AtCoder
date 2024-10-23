// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dd
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;cin >> n;
    cout << (n/3)+(n/5)+(n/7)-(n/(3*5))-(n/(3*7))-(n/(5*7))+(n/(3*5*7)) << '\n';
}
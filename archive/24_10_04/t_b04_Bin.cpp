// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cc

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
    int ans = 0;
    for (int i = 0; n > 0; i++) {
        if (n%2) ans += (1<<i);
        n/=10;
    }
    print(ans);

    return 0;
}

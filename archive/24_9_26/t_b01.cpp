// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bz

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

    int a,b;
    cin >> a >> b;
    print(a+b);

    return 0;
}

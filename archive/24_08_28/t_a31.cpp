// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ae

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    ll n;
    cin >> n;
    print((n/3)+(n/5)-(n/15));

    return 0;
}
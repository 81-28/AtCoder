// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_az

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

    int q;
    cin >> q;
    queue<string> qu;
    int query;
    string x;
    rep(i,q) {
        cin >> query;
        if (query == 1) {
            cin >> x;
            qu.push(x);
        }
        if (query == 2) print(qu.front());
        if (query == 3) qu.pop();
    }

    return 0;
}

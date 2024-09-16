// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ay

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
    stack<string> s;
    int query;
    string x;
    rep(i,q) {
        cin >> query;
        if (query == 1) {
            cin >> x;
            s.push(x);
        }
        if (query == 2) print(s.top());
        if (query == 3) s.pop();
    }

    return 0;
}

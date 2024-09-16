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
    int qu;
    string x;
    rep(i,q) {
        cin >> qu;
        if (qu == 1) {
            cin >> x;
            s.push(x);
        } else if (qu == 2) print(s.top());
        else if (qu == 3) s.pop();
    }

    return 0;
}

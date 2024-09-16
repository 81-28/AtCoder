// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bb

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
    map<string,int> m;
    int query,y;
    string x;
    rep(i,q) {
        cin >> query >> x;
        if (query == 1) {
            cin >> y;
            m[x] = y;
        }
        if (query == 2) print(m[x]);
    }

    return 0;
}

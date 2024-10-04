// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bc

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
    set<int> s;
    int query,x;
    rep(i,q) {
        cin >> query >> x;
        if (query == 1) s.insert(x);
        if (query == 2) s.erase(x);
        if (query == 3) {
            auto it = s.lower_bound(x);
            if (it == s.end()) print(-1);
            else print(*it);
        }
    }

    return 0;
}

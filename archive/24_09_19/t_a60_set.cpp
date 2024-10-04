// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bh

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)

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
    set<int> sa;
    map<int,int> m;
    int a;
    rep1(i,n) {
        cin >> a;
        auto it = sa.upper_bound(a);
        if (it == sa.end()) print(-1);
        else print(m[*it]);
        sa.insert(a);
        while (*sa.begin() != a) sa.erase(sa.begin());
        m[a] = i;
    }

    return 0;
}

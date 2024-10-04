// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bh

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using pii = pair<int,int>;

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
    set<pii> sa;
    pii p;
    rep1(i,n) {
        cin >> p.first;
        auto it = sa.upper_bound(p);
        if (it == sa.end()) print(-1);
        else print((*it).second);
        p.second = i;
        sa.insert(p);
        while ((*sa.begin()).first != p.first) sa.erase(sa.begin());
    }

    return 0;
}

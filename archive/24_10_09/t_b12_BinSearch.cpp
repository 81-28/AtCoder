// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ck

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)

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
    double l = 0.0, r = 50.0;
    double m;
    rep(_,16) {
        m = (l+r)/2;
        double f = m*m*m+m;
        if (n <= f) r = m;
        if (n > f) l = m;
    }
    print(l);

    return 0;
}

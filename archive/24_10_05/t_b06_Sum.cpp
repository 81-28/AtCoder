// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ce

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
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

    int n,q;
    cin >> n;
    vi a(n);
    cin >> a >> q;
    vi s(n+1,0);
    rep1(i,n) {
        s[i] = s[i-1]+a[i-1];
    }
    int l,r;
    int win,lose;
    rep1(k,q) {
        cin >> l >> r;
        win = s[r]-s[l-1];
        lose = r-(l-1)-win;
        if (win > lose) print("win");
        if (win == lose) print("draw");
        if (win < lose) print("lose");
    }

    return 0;
}

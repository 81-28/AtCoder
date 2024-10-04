// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bt

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
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

    int h,w,k;
    cin >> h >> w >> k;
    v<string> c(h);
    cin >> c;
    vi b(h,0);
    rep(i,h) {
        rep(j,w) {
            if (c[i][j] == '#') b[i]++;
        }
    }
    sort(all(b));

    int ans = 0;
    rep(i,h) {
        if (i < k) ans += w;
        else ans += b[i];
    }
    print(ans);

    return 0;
}

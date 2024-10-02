// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bv

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

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
    vi r(n),c(n);
    int p;
    rep(i,n) {
        rep(j,n) {
            cin >> p;
            if (p != 0) {
                r[i] = p;
                c[j] = p;
            }
        }
    }

    int ans = 0;
    for (int k = n; k > 1; k--) {
        rep(i,n) {
            if (r[i] == k) {
                ans += k-1-i;
                r.erase(r.begin()+i);
                break;
            }
        }
        rep(j,n) {
            if (c[j] == k) {
                ans += k-1-j;
                c.erase(c.begin()+j);
                break;
            }
        }
    }
    print(ans);

    return 0;
}
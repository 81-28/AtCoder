// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ab

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    int n,ans = 0;
    cin >> n;
    rep(i,n) {
        char t;
        int a;
        cin >> t >> a;
        if (t == '+') {
            ans += a;
        } else if (t == '-') {
            ans -= a;
        } else if (t == '*') {
            ans *= a;
        }
        if (ans < 0) ans += 10000;
        ans%=10000;
        print(ans);
    }

    return 0;
}

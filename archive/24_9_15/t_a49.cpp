// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aw

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

    vi x(21,0);
    int t;
    cin >> t;
    rep(i,t) {
        int p,q,r;
        cin >> p >> q >> r;
        int sum = x[p]+x[q]+x[r];
        if (sum > 0) {
            x[p]--;
            x[q]--;
            x[r]--;
            print('B');
        } else if (sum <= 0) {
            x[p]++;
            x[q]++;
            x[r]++;
            print('A');
        }
    }

    return 0;
}

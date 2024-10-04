// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ar

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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
    cin >> n >> q;
    vi a(n);
    rep1(i,n) {
        a[i-1] = i;
    }
    bool rev = false;
    rep(j,q) {
        int m,x,y;
        cin >> m;
        if (m == 1) {
            cin >> x >> y;
            if (rev) a[n-x] = y;
            else a[x-1] = y;
        } else if (m == 2) {
            rev = !rev;
        } else if (m == 3) {
            cin >> x;
            if (rev) print(a[n-x]);
            else print(a[x-1]);
        }
    }

    return 0;
}

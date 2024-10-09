// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cl

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
using ll = long long;
template<typename T>
using v = vector<T>;
using vll = v<ll>;

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

    int n;
    ll k;
    cin >> n >> k;
    vll a(n);
    cin >> a;
    ll ans = 0, sum = 0;
    int j = 0;
    rep(i,n) {
        for (; j < n; j++) {
            if (sum + a[j] <= k) sum += a[j];
            else break;
            // sum += a[j];
            // if (sum > k) {
            //     sum -= a[j];
            //     break;
            // }
        }
        ans += j-i;
        sum -= a[i];
    }
    print(ans);

    return 0;
}

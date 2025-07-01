// https://atcoder.jp/contests/abc373/tasks/abc373_c

#include <bits/stdc++.h>
using namespace std;

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

    int n;
    cin >> n;
    vi a(n),b(n);
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    print(a[n-1]+b[n-1]);

    return 0;
}

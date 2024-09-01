// https://atcoder.jp/contests/abc369/tasks/abc369_c

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    ll ans = n+(n-1);

    int combo = 0;
    for (int i = 0; i <= n-3; i++) {
        if (a[i+2]+a[i] == a[i+1]*2) {
            combo++;
            ans += combo;
        } else {
            combo = 0;
        }
    }

    print(ans);

    return 0;
}

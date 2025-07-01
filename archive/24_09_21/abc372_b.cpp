// https://atcoder.jp/contests/abc372/tasks/abc372_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(a) push_back(a)
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
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

    int m;
    cin >> m;
    vi a;
    while(m > 0) {
        a.pb(m%3);
        m/=3;
    }
    vi anss;
    rep(i,a.size()) {
        rep(j,a[i]) {
            anss.pb(i);
        }
    }
    print(anss.size());
    print(anss);

    return 0;
}

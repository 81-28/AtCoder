// https://atcoder.jp/contests/abc373/tasks/abc373_c

#include <bits/stdc++.h>
using namespace std;

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

template<typename T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }


int main() {
    fastio();

    int n;
    cin >> n;
    vi a(n),b(n);
    cin >> a >> b;
    print(max(a)+max(b));

    return 0;
}

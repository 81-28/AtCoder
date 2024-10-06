// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_al

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

    int t,n;
    cin >> t >> n;
    vi s(t,0);
    int l,r;
    rep(i,n) {
        cin >> l >> r;
        s[l]++;
        if (r != t) s[r]--;
    }
    for (int i = 1; i < t; i++) s[i] += s[i-1];
    print(s);

    return 0;
}

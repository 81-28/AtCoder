// https://atcoder.jp/contests/abc373/tasks/abc373_a

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)

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

    int ans = 0;
    string s;
    rep1(i,12) {
        cin >> s;
        if (s.size() == i) ans++;
    }
    print(ans);

    return 0;
}

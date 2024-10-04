// https://atcoder.jp/contests/abc373/tasks/abc373_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    cin >> s;
    map<char,int> c;
    rep(i,26) {
        c[s[i]] = i;
    }
    for (char i = 'B'; i <= 'Z'; i++) {
        char j = i-1;
        ans += (abs(c[i]-c[j]));
    }
    print(ans);

    return 0;
}

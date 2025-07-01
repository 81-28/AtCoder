// https://atcoder.jp/contests/abc375/tasks/abc375_a

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)

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

    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,n-2) {
        if (s.substr(i,3) == "#.#") ans++;
    }
    print(ans);

    return 0;
}

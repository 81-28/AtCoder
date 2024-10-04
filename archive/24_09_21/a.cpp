// https://atcoder.jp/contests/abc372/tasks/abc372_a

#include <bits/stdc++.h>
using namespace std;

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

    string s;
    cin >> s;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '.') {
            s.erase(s.begin()+i);
        }
    }
    print(s);

    return 0;
}

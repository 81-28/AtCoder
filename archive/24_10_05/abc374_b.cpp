// https://atcoder.jp/contests/abc374/tasks/abc374_b

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

    string s,t;
    cin >> s >> t;
    int sn = s.size();
    int tn = t.size();
    int n = max(sn,tn);
    rep(i,n) {
        if (s[i] != t[i]) {
            print(i+1);
            return 0;
        }
    }
    if (sn == tn) print(0);
    else print(n+1);

    return 0;
}

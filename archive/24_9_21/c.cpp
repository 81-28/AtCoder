// https://atcoder.jp/contests/abc372/tasks/abc372_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define substring(s,l,r) s.substr(l,r-l)

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

    int n,q;
    string s;
    cin >> n >> q >> s;
    int ans = 0;
    rep(i,n-2) {
        if (substring(s,i,i+3) == "ABC") {
            ans++;
            i+=2;
        }
    }
    int x;
    char c;
    rep(i,q) {
        cin >> x >> c;
        if (s[x-1] != c) {
            if (x <= n-2 && s.substr(x-1,3) == "ABC") ans--;
            if (2 <= x && x <= n-1 && s.substr(x-2,3) == "ABC") ans--;
            if (3 <= x && s.substr(x-3,3) == "ABC") ans--;
            s[x-1] = c;
            if (x <= n-2 && s.substr(x-1,3) == "ABC") ans++;
            if (2 <= x && x <= n-1 && s.substr(x-2,3) == "ABC") ans++;
            if (3 <= x && s.substr(x-3,3) == "ABC") ans++;
        }
        print(ans);
    }

    return 0;
}

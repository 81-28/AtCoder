// https://atcoder.jp/contests/abc376/tasks/abc376_b

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

    int n,q;
    cin >> n >> q;
    int ans = 0;
    char h;
    int t;
    int l = 1, r = 2;
    rep(i,q) {
        cin >> h >> t;
        if (h == 'L') {
            if ((l < t && t < r) || (r < l && l < t) || (t < r && r < l)) {
                ans += (t+n-l)%n;
            } else {
                ans += (l+n-t)%n;
            }
            l = t;
        }
        if (h == 'R') {
            if ((r < t && t < l) || (l < r && r < t) || (t < l && l < r)) {
                ans += (t+n-r)%n;
            } else {
                ans += (r+n-t)%n;
            }
            r = t;
        }
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc369/tasks/abc369_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    int n,ans = 0;
    cin >> n;
    int l = 0,r = 0;
    rep(i,n) {
        int a;
        char s;
        cin >> a >> s;
        if (s == 'L') {
            if (l != 0) {
                ans += abs(l-a);
            }
            l = a;
        } else {
            if (r != 0) {
                ans += abs(r-a);
            }
            r = a;
        }
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc375/tasks/abc375_b

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
    cin >> n;
    double ans = 0.0;
    double a = 0,b = 0;
    double x,y;
    rep(_,n) {
        cin >> x >> y;
        ans += sqrt(pow(a-x,2) + pow(b-y,2));
        a = x;
        b = y;
    }
    ans += sqrt(pow(a,2) + pow(b,2));
    cout << fixed << setprecision(20);
    print(ans);

    return 0;
}

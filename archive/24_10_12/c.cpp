// https://atcoder.jp/contests/abc375/tasks/abc375_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
template<typename T>
using v = vector<T>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
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

    int n;
    cin >> n;
    v<string> a(n);
    cin >> a;
    v<string> b = a;
    rep1(i,n/2) {
        if (i%4 == 1) {
            for (int j = i-1; j < n-i; j++) {
                b[i-1][j] = a[n-1-j][i-1];
                b[j][n-i] = a[i-1][j];
                b[n-i][n-1-j] = a[j][n-i];
                b[n-1-j][i-1] = a[n-i][n-1-j];
            }
        }
        if (i%4 == 2) {
            for (int j = i-1; j < n-i; j++) {
                b[i-1][j] = a[n-i][n-1-j];
                b[j][n-i] = a[n-1-j][i-1];
                b[n-i][n-1-j] = a[i-1][j];
                b[n-1-j][i-1] = a[j][n-i];
            }
        }
        if (i%4 == 3) {
            for (int j = i-1; j < n-i; j++) {
                b[i-1][j] = a[j][n-i];
                b[j][n-i] = a[n-i][n-1-j];
                b[n-i][n-1-j] = a[n-1-j][i-1];
                b[n-1-j][i-1] = a[i-1][j];
            }
        }
    }
    rep(i,n) print(b[i]);

    return 0;
}

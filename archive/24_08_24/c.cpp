// https://atcoder.jp/contests/abc368/tasks/abc368_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

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
    int n;
    cin >> n;
    vector<int> h(n);
    cin >> h;
    ll t = 0;
    rep(i,n) {
        int r = h[i]%5;
        t += (h[i]/5)*3;
        if (t%3 == 0) {
            if (r == 0) {
            } else if (r <= 1) {
                t++;
            } else if (r <= 2) {
                t += 2;
            } else {
                t += 3;
            }
        } else if (t%3 == 1) {
            if (r == 0) {
            } else if (r <= 1) {
                t++;
            } else {
                t += 2;
            }
        } else {
            if (r == 0) {
            } else if (r <= 3) {
                t++;
            } else {
                t += 2;
            }
        }
    }
    print(t);

    return 0;
}

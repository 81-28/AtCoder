// https://atcoder.jp/contests/abc377/tasks/abc377_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

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

template<typename T>
int sum(const vector<T>& v) { return accumulate(v.begin(),v.end(),0); }

int main() {
    fastio();

    v<string> s(8);
    cin >> s;
    vi r(8,1),c(8,1);
    rep(i,8) rep(j,8) {
        if (s[i][j] == '#') {
            r[i] = 0;
            c[j] = 0;
        }
    }
    print(sum(r)*sum(c));

    return 0;
}

// https://atcoder.jp/contests/abc370/tasks/abc370_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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
    vvi a(n,vi(n,0));
    rep(i,n) {
        rep(j,i+1) {
            cin >> a[i][j];
        }
    }
    int now = 1;
    rep(k,n) {
        int j = k;
        int i = now-1;
        if (i < j) {
            int temp = i;
            i = j;
            j = temp;
        }
        now = a[i][j];
    }
    print(now);

    return 0;
}

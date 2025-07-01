// https://atcoder.jp/contests/abc376/tasks/abc376_a

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
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


int main() {
    fastio();

    int n,c;
    cin >> n >> c;
    vi t(n);
    cin >> t;
    int ans = 1;
    int last = t[0];
    rep1(i,n-1) {
        if (t[i]-last >= c) {
            ans++;
            last = t[i];
        }
    }
    print(ans);

    return 0;
}

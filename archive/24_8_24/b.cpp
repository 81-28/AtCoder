// https://atcoder.jp/contests/abc368/tasks/abc368_b

#include <bits/stdc++.h>
using namespace std;

#define rall(v) v.rbegin(), v.rend()

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
    int n,ans = 0;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(rall(a));
    while(a[1] != 0) {
        a[0]--;
        a[1]--;
        ans++;
        sort(rall(a));
    }
    print(ans);

    return 0;
}

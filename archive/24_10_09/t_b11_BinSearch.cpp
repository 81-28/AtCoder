// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cj

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

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
    int n,q;
    cin >> n;
    vector<int> a(n);
    cin >> a >> q;
    sort(all(a));
    int l,r;
    int x,m;
    rep(_,q) {
        cin >> x;
        l = 0, r = n;
        while (l<r) {
            m = (l+r)/2;
            if (x <= a[m]) r = m;
            if (x > a[m]) l = m+1;
        }
        print(l);
    }

    return 0;
}

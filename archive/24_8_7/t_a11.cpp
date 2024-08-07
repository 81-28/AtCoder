// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_k

#include <bits/stdc++.h>
using namespace std;

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
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    cin >> a;
    int l = 0, r = n-1;
    int m = (l+r)/2;
    do {
        if (a[m] < x)
        {
            l = m+1;
            m = (l+r)/2;
        } else if (x < a[m])
        {
            r = m-1;
            m = (l+r)/2;
        }
    } while (a[m] != x);
    print(m+1);

    return 0;
}

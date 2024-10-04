// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ag

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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int s = a[0];
    for (int i = 1; i < n; i++) {
        s ^= a[i];
    }
    if (s == 0) print("Second");
    else print("First");

    return 0;
}

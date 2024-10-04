// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_j

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    int n,d;
    cin >> n;
    vector<int> a(n);
    cin >> a >> d;
    vector<int> lm(n),rm(n);
    lm[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        lm[i] = max(lm[i-1],a[i]);
    }
    rm[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        rm[i] = max(rm[i+1],a[i]);
    }

    rep(i,d) {
        int l,r;
        cin >> l >> r;
        print(max(lm[l-2],rm[r]));
    }

    return 0;
}

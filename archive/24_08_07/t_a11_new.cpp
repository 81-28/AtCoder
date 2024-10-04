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


int binSearch(vector<int> a, int x) {
    int l = 0,r = a.size()-1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (x < a[m]) r = m-1;
        if (x == a[m]) return m;
        if (x > a[m]) l = m+1;
    }
    return -1;
}

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    cin >> a;
    print(binSearch(a,x)+1);

    return 0;
}

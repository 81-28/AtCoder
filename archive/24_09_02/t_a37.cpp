// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ak

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
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

ll sumLL(const vector<int>& v) { return accumulate(all(v),0LL); }


int main() {
    ll n,m,b;
    cin >> n >> m >> b;
    vector<int> a(n),c(m);
    cin >> a >> c;
    print((b*n*m)+m*sumLL(a)+n*sumLL(c));

    return 0;
}

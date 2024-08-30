// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
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
    vector<int> a(n),b(n);
    cin >> a;
    b = a;
    sort(all(b));
    for (int i = n-1; i > 0; i--)
    {
        if (b[i] == b[i-1])
        {
            b.erase(b.begin()+i);
        }
    }
    rep(i,n) {
        cout << distance(b.begin(),lower_bound(all(b),a[i]))+1 << " ";
    }
    cout << endl;

    return 0;
}

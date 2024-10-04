// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_x

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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> l;
    rep(i,n) {
        auto pos = lower_bound(all(l),a[i]);
        // lが空である、もしくはlの現在の最後の要素よりもa[i]が大きい場合、lに追加
        if (pos == l.end()) {
            l.push_back(a[i]);
        } else {
            // それ以外の場合、posの位置の値をa[i]に置き換える
            *pos = a[i];
        }
    }
    print(l.size());

    return 0;
}

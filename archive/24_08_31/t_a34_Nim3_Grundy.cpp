// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ah

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
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    cin >> a;
    int ma = 0;
    rep(i,n) {
        ma = max(ma,a[i]);
    }

    // grundy[i] : 石がi個の時のGrundy数
    // transit[i]: Grundy数がiとなるような遷移ができるか
    vector<int> grundy(ma+1);
    rep(i,ma+1) {
        vector<bool> transit(3,false);
        if (i >= x) transit[grundy[i-x]] = true;
        if (i >= y) transit[grundy[i-y]] = true;
        if (!transit[0]) grundy[i] = 0;
        else if (!transit[1]) grundy[i] = 1;
        else grundy[i] = 2;
    }

    int s = 0;
    rep(i,n) {
        s ^= grundy[a[i]];
    }
    if (s == 0) print("Second");
    else print("First");

    return 0;
}

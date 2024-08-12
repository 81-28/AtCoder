// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_p

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


int main() {;
    int n;
    cin >> n;
    vector<int> a(n-1),b(n-2),ans(n,0);
    cin >> a >> b;
    a.insert(a.begin(),0);
    b.insert(b.begin(),0);
    b.insert(b.begin(),0);
    ans[1] = a[1];
    for (int i = 2; i < n; i++)
    {
        ans[i] = min(ans[i-1]+a[i],ans[i-2]+b[i]);
    }
    print(ans[n-1]);

    return 0;
}

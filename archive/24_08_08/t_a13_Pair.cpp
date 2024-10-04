// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_m

#include <bits/stdc++.h>
using namespace std;

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


int main() {
    ll ans = 0;
    int n,k;
    cin >> n >> k;
    vector<int> a(n),r(n-1);
    cin >> a;
	// しゃくとり法
    // 1つ前の答え(範囲の右端)を使う
    for (int i = 0; i < n-1; i++)
    {
        if (i==0) r[i] = 0;
        else r[i] = r[i-1];

        while (r[i] < n-1 && a[r[i]+1]-a[i] <= k)
        {
            r[i]++;
        }
        ans += (r[i]-i);
    }
    print(ans);

    return 0;
}

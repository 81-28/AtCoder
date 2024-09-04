// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_an

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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

// nCr を計算する関数
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;

    ll result = 1;
    for (int i = 1; i <= r; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}


int main() {
    fastio();

    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[a]++;
    }

    ll ans = 0;
    for (const auto &pair : mp) {
        ans += nCr(pair.second,3);
    }
    print(ans);


    return 0;
}

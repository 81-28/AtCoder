// https://atcoder.jp/contests/tessoku-book/tasks/typical90_a

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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


int n,l,k;
vi a;
// スコアxが実現可能かどうかを返す関数
bool check(const int& x) {
    int cutCount = 0, lastA = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]-lastA >= x && l-a[i] >= x) {
            cutCount++;
            lastA = a[i];
        }
    }
    return cutCount >= k;
}

int main() {
    fastio();

    cin >> n >> l >> k;
    a = vi(n);
    cin >> a;

    // スコアを二分探索
    ll left = 1, right = l, mid;
    while (left < right) {
        mid = (left+right+1)/2;
        if (check(mid)) left = mid;
        else right = mid-1;
    }
    print(left);

    return 0;
}

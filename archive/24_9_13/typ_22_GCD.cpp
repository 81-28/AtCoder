// https://atcoder.jp/contests/typical90/tasks/typical90_v

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    fastio();

    ll a,b,c;
    cin >> a >> b >> c;
    ll g = gcd(a,gcd(b,c));
    print((a/g -1) + (b/g -1) + (c/g -1));

    return 0;
}

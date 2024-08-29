// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ad

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

// 素数 p に対する a^b の計算を行い、m で割った余りを返す関数
ll ModPower(ll a, ll b, ll m) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

// a ÷ b を m で割った余りを返す関数
ll Division(ll a, ll b, ll m) {
    return (a * ModPower(b, m - 2, m)) % m;
}

int main() {
    ll m = 1000000007;
    int n,r;
    cin >> n >> r;
    int nr = r > n-r ? r : n-r;
    ll a = 1,b = 1;
    rep1(i,nr) {
        a *= n+1-i;
        a %= m;
        b *= i;
        b %= m;
    }
    print(Division(a,b,m));

    return 0;
}

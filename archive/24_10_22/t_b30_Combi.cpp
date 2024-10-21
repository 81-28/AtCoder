// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dc

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
    fastio();

    int mod = 1e9+7;
    int h,w;
    cin >> h >> w;
    h--;w--;
    int n = h+w;
    int r = min(h,w);
    ll a = 1,b = 1;
    rep1(i,r) {
        a = (a*(n+1-i))%mod;
        b = (b*i)%mod;
    }
    print(Division(a,b,mod));

    return 0;
}

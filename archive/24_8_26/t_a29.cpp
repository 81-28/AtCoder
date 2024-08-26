// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_aq

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


int main() {
    int a,b;
    cin >> a >> b;
    ll ans = 1;
    int d = log2(b);
    // an[i] : a^(2^i)
    vector<ll> an(d+1);
    an[0] = a;
    if (b%2) {
        ans *= a;
        ans %= 1000000007;
    }
    rep1(i,d) {
        an[i] = an[i-1] * an[i-1];
        an[i] %= 1000000007;
        if (b/(1<<i)%2) {
            ans *= an[i];
            ans %= 1000000007;
        }
    }
    print(ans);

    return 0;
}

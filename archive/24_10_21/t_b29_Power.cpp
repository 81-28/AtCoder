// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_db

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
using ll = long long;
template<typename T>
using v = vector<T>;
using vll = v<ll>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    fastio();

    int mod = 1e9+7;
    int a;ll b;
    cin >> a >> b;
    ll ans = 1;
    int d = log2(b);
    // an[i] : a^(2^i)
    vll an(d+1);
    an[0] = a;
    if(b%2) ans = (ans*a)%mod;
    rep1(i,d) {
        an[i] = (an[i-1]*an[i-1])%mod;
        if((b>>i)%2) ans = (ans*an[i])%mod;
    }
    print(ans);

    return 0;
}

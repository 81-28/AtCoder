// https://atcoder.jp/contests/abc375/tasks/abc375_d

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define pb(a) push_back(a)
using ll = long long;
template<typename T>
using v = vector<T>;
using vll = v<ll>;
using vvll = v<vll>;

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

    string s;
    cin >> s;
    int n = s.size();
    vvll cns(26);
    rep(i,n) {
        cns[s[i]-'A'].pb(i);
    }
    ll ans = 0;
    vll cn;
    ll m;
    rep(i,26) {
        cn = cns[i];
        m = cn.size();
        for (ll j = 0; j < m; j++) {
            ans += (2*j-m+1)*cn[j];
        }
        ans -= m*(m-1)/2;
    }
    print(ans);

    return 0;
}

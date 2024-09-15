// https://atcoder.jp/contests/abc371/tasks/abc371_d

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
template<typename T>
using v = vector<T>;
using vi = v<int>;

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

    int n,q;
    cin >> n;
    vi x(n+1);
    map<int,ll> p;
    x[0] = INT_MIN;
    p[INT_MIN] = 0;
    rep1(i,n) {
        cin >> x[i];
    }
    rep1(i,n) {
        cin >> p[x[i]];
        p[x[i]] += p[x[i-1]];
    }
    cin >> q;
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        auto lIt = lower_bound(all(x),l);
        auto rIt = upper_bound(all(x),r);
        lIt--;
        rIt--;
        print(p[*rIt]-p[*lIt]);
    }

    return 0;
}

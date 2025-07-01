// https://atcoder.jp/contests/abc374/tasks/abc374_e

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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


int n;
vll a,p,b,q;
ll cost(const ll& w) {
    ll sum = 0;
    rep(i,n) {
        ll c=a[i], r=p[i], d=b[i], s=q[i];
        if ((c*s == r*d && a[i] > b[i]) || c*s < d*r) {
                c=b[i], r=q[i], d=a[i], s=p[i];
        }
        if (w%c == 0) {
            sum += r*w/c;
        } else {
            int j = w/c;
            int count = 0;
            for (int k = c*j; k < w; k+=d) count++;
            sum += min(r*j + s*count, r*(j+1));
        }
    }
    return sum;
}

int main() {
    fastio();

    ll x;
    cin >> n >> x;
    a = vll(n);
    p = vll(n);
    b = vll(n);
    q = vll(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll l = 0, r = 100*x;
    ll m;
    while (l < r) {
        m = (l+r)/2;
        ll cm = cost(m);
        if (cm > x) r = m;
        if (cm <= x) l = m+1;
    }
    print(l);

    return 0;
}

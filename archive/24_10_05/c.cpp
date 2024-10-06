// https://atcoder.jp/contests/abc374/tasks/abc374_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
template<typename T>
using v = vector<T>;
using vll = v<ll>;

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

template<typename T>
ll sumLL(const vector<T>& v) { return accumulate(v.begin(),v.end(),0LL); }


int main() {
    fastio();

    int n;
    cin >> n;
    vll k(n);
    cin >> k;
    ll sumK = sumLL(k);
    set<ll> s;
    ll sum;
    rep(i,1<<n) {
        sum = 0;
        rep(j,n) {
            if ((i>>j)%2) {
                sum += k[j];
            }
        }
        s.insert(sum);
    }
    print(*s.lower_bound((sumK+1)/2));


    return 0;
}

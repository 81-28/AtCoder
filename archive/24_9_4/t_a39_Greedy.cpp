// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_bn

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;
using pii = pair<int,int>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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


int main() {
    fastio();

    int n;
    cin >> n;
    v<pii> t(n);
    rep(i,n) cin >> t[i].second >> t[i].first;
    sort(all(t));
    vi l(n),r(n);
    rep(i,n) {
        l[i] = t[i].second;
        r[i] = t[i].first;
    }

    int ans = 0;
    int currentTime = 0;
    rep(i,n) {
        if (currentTime <= l[i]) {
            currentTime = r[i];
            ans++;
        }
    }
    print(ans);

    return 0;
}

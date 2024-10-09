// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cm

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define YesNo(x) cout<<(x ? "Yes\n":"No\n")
using ll = long long;
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}


int main() {
    fastio();

    int n,k;
    cin >> n >> k;
    // 半分に分けて、それぞれでbit全探索
    vi a(n/2),b(n-n/2);
    cin >> a >> b;

    unordered_set<ll> s;
    ll sum;
    rep(i,1<<(n-n/2)) {
        sum = 0;
        rep(j,n-n/2) {
            if ((i>>j)%2) sum += b[j];
        }
        s.insert(sum);
    }
    rep(i,1<<(n/2)) {
        sum = 0;
        rep(j,n/2) {
            if ((i>>j)%2) sum += a[j];
        }
        if (s.find(k-sum) != s.end()) {
            YesNo(true);
            return 0;
        }
    }
    YesNo(false);

    return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_l

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;

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


ll amount(const vector<int>& a,const ll& m) {
    ll sum = 0;
    rep(i,a.size()) {
        sum += (m/a[i]);
    }
    return sum;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    int l = 1, r = 1e9;
    ll m;
    while (l<r) {
        m = (l+r)/2;
        ll am = amount(a,m);
        if (k <= am) r = m;
        if (k > am) l = m+1;
    }
    print(l);

    return 0;
}

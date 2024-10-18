// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cw

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;
using pii = pair<int,int>;

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

    int n;
    cin >> n;
    int x,y;
    v<pii> p(n);
    rep(i,n) {
        cin >> x >> y;
        p[i] = {x,-y};
    }
    // xを昇順,xが同じ場合yを降順にソート
    sort(all(p));
    vi a(n);
    rep(i,n) a[i] = -p[i].second;

    vi l;
    rep(i,n) {
        auto pos = lower_bound(all(l),a[i]);
        if (pos == l.end()) l.push_back(a[i]);
        else *pos = a[i];
    }
    print(l.size());

    return 0;
}

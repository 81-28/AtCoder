// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ap

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<typename T>
using v = vector<T>;
using pii = pair<int,int>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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

    int n,k;
    cin >> n >> k;
    v<pii> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;

    int ans = 0;
    for (int i = 1; i+k <= 100; i++) {
        for (int j = 1; j+k <= 100; j++) {
            int count = 0;
            for (const auto &p : ps) {
                if (i <= p.first && p.first <= i+k && j <= p.second && p.second <= j+k) count++;
            }
            ans = max(ans,count);
        }
    }
    print(ans);

    return 0;
}

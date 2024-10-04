// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_al

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

int sum(const vector<int>& v) { return accumulate(all(v),0); }

int main() {
    int d,n;
    cin >> d >> n;
    vector<int> ans(d,24);
    rep(i,n) {
        int l,r,h;
        cin >> l >> r >> h;
        for (int j = l-1; j < r; j++) {
            ans[j] = min(ans[j],h);
        }
    }
    print(sum(ans));

    return 0;
}
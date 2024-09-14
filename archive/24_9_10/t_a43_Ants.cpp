// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aq

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

    int n,l;
    cin >> n >> l;
    int ans = 0;
    rep(i,n) {
        int a;
        char b;
        cin >> a >> b;
        if (b == 'E') ans = max(ans,l-a);
        else ans = max(ans,a);
    }
    print(ans);

    return 0;
}

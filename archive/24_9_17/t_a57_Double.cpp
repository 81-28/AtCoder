// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_be

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

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
    cin >> n >> q;
    // a[i][j] : 穴jから2^i日後に辿り着く穴
    vvi a(30,vi(n+1,0));
    rep1(j,n) cin >> a[0][j];
    rep1(i,29) {
        rep1(j,n) a[i][j] = a[i-1][a[i-1][j]];
    }
    int x,y,i;
    rep1(k,q) {
        cin >> x >> y;
        i = 0;
        for (int j = y; j > 0; j/=2) {
            if (j%2) x = a[i][x];
            i++;
        }
        print(x);
    }

    return 0;
}

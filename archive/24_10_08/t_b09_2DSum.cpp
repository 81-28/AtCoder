// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ch

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
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

    int n;
    cin >> n;
    vvi p(1502,vi(1502,0));
    int a,b,c,d;
    rep1(_,n) {
        cin >> a >> b >> c >> d;
        p[a+1][b+1]++;
        p[a+1][d+1]--;
        p[c+1][b+1]--;
        p[c+1][d+1]++;
    }
    int ans = 0;
    rep1(i,1500) rep1(j,1500) {
        p[i][j] += p[i][j-1]+p[i-1][j]-p[i-1][j-1];
        if (p[i][j] > 0) ans++;
    }
    print(ans);

    return 0;
}

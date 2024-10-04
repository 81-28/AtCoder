// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_br

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

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


int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    int na = 0;
    rep(i,a.size()) {
        if (a[i]) na += (1<<i);
    }
    vi b(m,0);
    int x,y,z;
    rep(i,m) {
        cin >> x >> y >> z;
        b[i] += (1<<(x-1));
        b[i] += (1<<(y-1));
        b[i] += (1<<(z-1));
    }
    // A18のような解き方
    // dp[i][j] : 最初のi操作まで(のうち何個か選んで)でjが作れるかどうかの表
    v<v<bool>> dp(m+1,v<bool>(1<<n,false));
    // 最低何回の操作で可能かの記録
    v<v<int>> dpn(m+1,v<int>(1<<n,INT_MAX));
    dp[0][na] = true;
    dpn[0][na] = 0;
    rep1(i,m) {
        rep(j,1<<n) {
            if (dp[i-1][j ^ b[i-1]]) {
                dp[i][j] = true;
                dpn[i][j] = min(dpn[i][j],dpn[i-1][j ^ b[i-1]] + 1);
            }
            if (dp[i-1][j]) {
                dp[i][j] = true;
                dpn[i][j] = min(dpn[i][j],dpn[i-1][j]);
            }
            
        }
    }

    // int ans = dpn[m][(1<<n)-1];
    // 何故か下の方法の方が速い
    int ans = INT_MAX;
    rep(i,m+1) {
        if (dp[i][(1<<n)-1]) ans = min(ans,dpn[i][(1<<n)-1]);
    }
    if (ans == INT_MAX) print(-1);
    else print(ans);

    return 0;
}

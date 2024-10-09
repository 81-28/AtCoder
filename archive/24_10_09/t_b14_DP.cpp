// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cm

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
#define YesNo(x) cout<<(x ? "Yes\n":"No\n")
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

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    // dp[i][j] : i枚目までで合計jが可能か
    v<v<bool>> dp(n+1,v<bool>(k+1,false));
    for (int i=0; i<=n; i++) dp[i][0] = true;

    rep1(i,n) {
        rep1(j,k) {
            if ((dp[i-1][j]) || (j-a[i-1] >= 0 && dp[i-1][j-a[i-1]])) dp[i][j] = true;
        }
        if (dp[i][k]) {
            YesNo(true);
            return 0;
        }
    }
    YesNo(false);

    return 0;
}

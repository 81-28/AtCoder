// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_de

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
#define all(v) v.begin(), v.end()
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
    vi a(k);
    cin >> a;
    sort(all(a));
    // dp[i] : 石がi個の状態でターンが回ってきたとき、勝つかどうか(相手を負けにできるかどうか)
    v<bool> dp(n+1,0);
    rep1(i,n)rep(j,k){
        if (i-a[j] >= 0){
            if (!dp[i-a[j]]){
                dp[i] = 1;
                break;
            } else continue;
        } else break;
    }
    if (dp[n]) print("First");
    else print("Second");

    return 0;
}

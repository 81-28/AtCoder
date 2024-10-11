// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cp

#include <bits/stdc++.h>
using namespace std;

#define rep2(i,s,n) for (int i=(int)(s); i<(int)(n); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
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

    int n;
    cin >> n;
    vi h(n);
    cin >> h;
    // dp[i] : 足場iに来る方法の最小コスト
    // p[i] : 最良の方法で足場iに来る場合の、来る前の足場
    vi dp(n+1), p(n+1,0);
    dp[1] = 0;
    dp[2] = abs(h[1]-h[0]);
    p[2] = 1;
    int pre1,pre2;
    rep2(i,3,n+1) {
        pre1 = dp[i-1]+abs(h[i-1]-h[i-2]);
        pre2 = dp[i-2]+abs(h[i-1]-h[i-3]);
        if (pre1 < pre2) {
            dp[i] = pre1;
            p[i] = i-1;
        } else {
            dp[i] = pre2;
            p[i] = i-2;
        }
    }
    vi anss;
    for (int i = n; i != 0; i = p[i]) anss.insert(anss.begin(),i);
    print(anss.size());
    print(anss);

    return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cq

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define pb(a) push_back(a)
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

    int n,s;
    cin >> n >> s;
    vi a(n);
    cin >> a;
    // dp[i][j] : i枚目までで合計jが可能かどうか。可能ならば、遷移前(i-1)のjを記録しておく
    v<v<pair<bool,int>>> dp(n+1,v<pair<bool,int>>(s+1,{false,0}));
    dp[0][0].first = true;
    int preJ;
    int i = 1;
    for(; i <= n; i++) {
        rep(j,s+1) {
            if (dp[i-1][j].first) dp[i][j] = {true,j};
            preJ = j-a[i-1];
            if (preJ >= 0 && dp[i-1][preJ].first) dp[i][j] = {true,preJ};
        }
        if (dp[i][s].first) break;
    }
    if (i == n+1 && !dp[n][s].first) print(-1);
    else {
        vi anss;
        int nowJ = s;
        int nextJ;
        for (int k = i; k > 0; k--) {
            nextJ = dp[k][nowJ].second;
            if (nowJ != nextJ) {
                anss.pb(k);
                if (nextJ == 0) break;
            }
            nowJ = nextJ;
        }
        print(anss.size());
        print(anss);
    }

    return 0;
}

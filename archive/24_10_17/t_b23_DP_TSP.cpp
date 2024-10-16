// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cv

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
template<typename T>
using v = vector<T>;
using pii = pair<int,int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


double distance(const pii& p, const pii& q) {
    return sqrt(pow(p.first - q.first, 2) + pow(p.second - q.second, 2));
}

int main() {
    fastio();

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) {
        cin >> p[i].first >> p[i].second;
    }

    // dp[i][j] : nbitのiで表された訪問済みの状態で、現在jに居るときの最短距離
    v<v<double>> dp(1<<n,v<double>(n,1e9));
    // 都市0からスタートし、全通りの回り方を試す(最後に都市0に戻ることでループが完成する)
    dp[0][0] = 0;
    // 配るDP
    rep(i,(1<<n)-1) rep(j,n) {
        if (dp[i][j] == 1e9) continue;
        rep(k,n) {
            if ((i>>k)%2) continue; // 訪問済みの都市には行かない
            if (k!=0 || i == (1<<n)-2) dp[i+(1<<k)][k] = min(dp[i+(1<<k)][k],dp[i][j]+distance(p[j],p[k]));
        }
    }

    cout << fixed << setprecision(12);
    // 全て訪問し、最短となる1周の長さを出力
    print(dp[(1<<n)-1][0]);

    return 0;
}

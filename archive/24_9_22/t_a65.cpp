// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bm

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
    vvi g(n+1);
    vi a(n+1,0);
    vi anss(n,-1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        g[a[i]].pb(i);
    }
    queue<int> q;
    rep1(i,n) {
        if (g[i].size() == 0) {
            anss[i-1] = 0;
            q.push(a[i]);
        }
    }
    // 全員1まで辿り着くので、この条件
    while (anss[0] == -1) {
        int pos = q.front();
        q.pop();
        if (anss[pos-1] != -1) continue;

        vi nexG = g[pos];
        bool ok = true;
        int sum = 0;
        rep(i,nexG.size()) {
            if (anss[nexG[i]-1] == -1) {
                ok = false;
                break;
            } else sum += (anss[nexG[i]-1] + 1);
        }
        if (!ok) continue;
        anss[pos-1] = sum;

        q.push(a[pos]);
    }
    print(anss);

    return 0;
}

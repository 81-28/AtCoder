// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_at

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<typename T>
using v = vector<T>;
using vi = v<int>;
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

    vi anss(n+1);
    v<bool> visited(n,false);
    int now = 0;
    visited[0] = true;
    anss[0] = 1;
    for (int i = 1; i < n; i++) {
        double dist = 1500.0;
        int index = -1;
        rep(j,n) {
            if (visited[j]) continue;
            else {
                double newdist = distance(p[now],p[j]);
                if (newdist < dist) {
                    dist = newdist;
                    index = j;
                }
            }
        }
        now = index;
        visited[index] = true;
        anss[i] = index+1;
    }
    anss[n] = 1;

    rep(i,n+1) {
        print(anss[i]);
    }

    return 0;
}

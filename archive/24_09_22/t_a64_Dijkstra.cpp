// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bl

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
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


int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    v<v<pii>> g(n+1);
    int a,b,c;
    rep1(i,m) {
        cin >> a >> b >> c;
        g[a].pb(pii({b,c}));
        g[b].pb(pii({a,c}));
    }
    vi dist(n+1,INT_MAX);
    dist[1] = 0;
    // q = {距離, 位置}
    priority_queue<pii, v<pii>, greater<pii>> q;
    q.push({0,1});
    while(!q.empty()) {
        int d = q.top().first;
        int pos = q.top().second;
        q.pop();
        if (d > dist[pos]) continue;
        v<pii> nexG = g[pos];
        for (int i = 0; i < (int)nexG.size(); i++) {
            int next = nexG[i].first;
            int cost = nexG[i].second;
            if (dist[next] > dist[pos]+cost) {
                dist[next] = dist[pos]+cost;
                q.push({dist[next],next});
            }
        }
    }
    rep1(k,n) {
        if (dist[k] == INT_MAX) print(-1);
        else print(dist[k]);
    }

    return 0;
}

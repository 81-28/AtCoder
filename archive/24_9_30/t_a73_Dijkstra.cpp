// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bu

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(a) push_back(a)
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


struct Edge {
    int to, len, tree;
};

int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    v<v<Edge>> g(n+1);
    int a,b,c,d;
    rep(i,m) {
        cin >> a >> b >> c >> d;
        g[a].pb(Edge({b,c,d}));
        g[b].pb(Edge({a,c,d}));
    }
    // dist = {距離, 木の本数}
    v<pii> dist(n+1,{INT_MAX,0});
    dist[1] = {0,0};
    // q = {距離, 位置}
    priority_queue<pii, v<pii>, greater<pii>> q;
    q.push({0,1});
    int pos;
    while(!q.empty()) {
        d = q.top().first;
        pos = q.top().second;
        q.pop();
        if (d > dist[pos].first) continue;
        v<Edge> nexG = g[pos];
        for (int i = 0; i < (int)nexG.size(); i++) {
            int next = nexG[i].to;
            int cost = nexG[i].len;
            int t = nexG[i].tree;
            // 採用基準を調整(距離が同じで、木の本数が多いと採用)
            if (dist[next].first > dist[pos].first+cost || (dist[next].first == dist[pos].first+cost && dist[next].second < dist[pos].second+t)) {
                dist[next].first = dist[pos].first+cost;
                dist[next].second = dist[pos].second+t;
                q.push({dist[next].first,next});
            }
        }
    }
    print(dist[n].first,dist[n].second);

    return 0;
}

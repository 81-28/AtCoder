// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_am

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
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


vvi g;
v<bool> visited;

void dfs(const int& pos) {
    visited[pos] = true;
    rep(i,g[pos].size()) {
        int next = g[pos][i];
        if (!visited[next]) dfs(next);
    }
}

int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    int a,b;
    rep(i,m) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    visited = v<bool>(n+1,false);
    dfs(1);

    bool ok = true;
    rep1(i,n) {
        if (!visited[i]) {
            ok = false;
            break;
        }
    }
    if (ok) print("The graph is connected.");
    else print("The graph is not connected.");

    return 0;
}

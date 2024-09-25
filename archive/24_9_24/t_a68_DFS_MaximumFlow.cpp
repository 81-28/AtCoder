// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    int to, cap, rev;
};

class MaximumFlow {
public:
    int siz = 0;
    vector<bool> used;
    vector<vector<Edge>> g;
    MaximumFlow(const int& n) {
        siz = n;
        used = vector<bool>(n+1);
        g = vector<vector<Edge>>(n+1,vector<Edge>(n+1));
    }

    // 頂点aからbに向かう、上限c L/s の辺を追加
    void addEdge(const int& a, const int& b, const int& c) {
        int nga = g[a].size();
        int ngb = g[b].size();
        g[a].push_back(Edge{b,c,ngb});
        g[b].push_back(Edge{a,0,nga});
    }

	// 深さ優先探索（f はスタートから pos に到達する過程での " 残余グラフの辺の容量 " の最小値）
	// 返り値は流したフローの量（流せない場合は 0 を返す）
    int dfs(const int& pos, const int& goal, const int& f) {
        // ゴールに到着:フローを流せる
        if (pos == goal) return f;
        used[pos] = true;

        for (int i = 0; i < g[pos].size(); i++) {
            // 容量0の辺は使えない
            if (g[pos][i].cap == 0) continue;
            // 既に訪問した頂点には行っても意味ない
            if (used[g[pos][i].to]) continue;
            // 目的地までのパスを探す
            int flow = dfs(g[pos][i].to, goal, min(f,g[pos][i].cap));
            // フローを流せる場合、残余グラフの容量をflowだけ増減させる
            if (flow >= 1) {
                g[pos][i].cap -= flow;
                g[g[pos][i].to][g[pos][i].rev].cap += flow;
                return flow;
            }
        }
        // 全ての辺を探索しても見つからなかった
        return 0;
    }

    // 頂点sからtまでの最大フローの総流量を返す
    int maxFlow(const int& s, const int& t) {
        int totalFlow = 0;
        while (true) {
            used = vector<bool>(siz+1,false);
            int f = dfs(s,t,INT_MAX);
            if (f == 0) break;
            totalFlow += f;
        }
        return totalFlow;
    }
};

int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    MaximumFlow f(n);
    int a,b,c;
    rep(i,m) {
        cin >> a >> b >> c;
        f.addEdge(a,b,c);
    }
    print(f.maxFlow(1,n));

    return 0;
}

// https://atcoder.jp/contests/abc205/tasks/abc205_f

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct Edge {
    int to, cap, rev;
};

class MaximumFlow {
public:
    int siz=0;
    vector<bool> used;
    vector<vector<Edge>> g;
    MaximumFlow(const int& n) {
        siz=n;
        used=vector<bool>(n);
        g=vector<vector<Edge>>(n,vector<Edge>(n));
    }

    // 頂点aからbに向かう、上限c L/s の辺を追加
    void addEdge(const int& a, const int& b, const int& c) {
        int nga=g[a].size();
        int ngb=g[b].size();
        g[a].push_back(Edge{b,c,ngb});
        g[b].push_back(Edge{a,0,nga});
    }

	// 深さ優先探索（f はスタートから pos に到達する過程での " 残余グラフの辺の容量 " の最小値）
	// 返り値は流したフローの量（流せない場合は 0 を返す）
    int dfs(const int& pos, const int& goal, const int& f) {
        // ゴールに到着:フローを流せる
        if (pos==goal) return f;
        used[pos]=1;

        for (int i=0; i < g[pos].size(); ++i) {
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
        int totalFlow=0;
        while (1) {
            used = vector<bool>(siz,0);
            int f = dfs(s,t,INF);
            if (f==0) break;
            totalFlow += f;
        }
        return totalFlow;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int h,w,n;
    cin >> h >> w >> n;
    int m=max({h,w,n});
    MaximumFlow f(m*6);
    rep(i,h) f.addEdge(0, m+i, 1);
    rep(k,n) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for (int i=a-1; i<c; ++i) f.addEdge(m+i, m*2+k, 1);
        f.addEdge(m*2+k, m*3+k, 1);
        for (int i=b-1; i<d; ++i) f.addEdge(m*3+k, m*4+i, 1);
    }
    rep(i,w) f.addEdge(m*4+i, m*5, 1);
    print(f.maxFlow(0,m*5));

    return 0;
}

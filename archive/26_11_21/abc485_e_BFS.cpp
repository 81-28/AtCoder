// https://atcoder.jp/contests/abc485/tasks/abc485_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define pb push_back

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // {行先,色}
    v<v<pii>> g(n);
    while (m--) {
        int u,v,c;
        cin >> u >> v >> c;
        g[--u].pb({--v,--c});
    }

    // 各位置に最初に来た2種の色
    // -2:未登録, -1:開始地点
    vi c1(n,-2),c2(n,-2);
    // {距離,位置,色}
    queue<tuple<int,int,int>> q;
    c1[0]=-1;
    q.push({0,0,-1});
    while (!q.empty()) {
        auto[dist,pos,c]=q.front();
        q.pop();
        if (pos==n-1) {
            print(dist);
            return 0;
        }
        for (auto[nxt,nc]:g[pos]) {
            if (nc==c) continue;
            if (c1[nxt]==nc || c2[nxt]==nc) continue;
            // 2色で訪問済みなら、不要
            if (c1[nxt]!=-2 && c2[nxt]!=-2) continue;
            if (c1[nxt]==-2) c1[nxt]=nc;
            else c2[nxt]=nc;
            q.push({dist+1,nxt,nc});
        }
    }
    print(-1);

    return 0;
}

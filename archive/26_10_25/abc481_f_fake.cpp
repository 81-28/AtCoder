// https://atcoder.jp/contests/abc481/tasks/abc481_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using pii=pair<int,int>;
using mint=modint998244353;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<tuple<int,int,int>> t(m);
    v<v<pii>> g(n);
    for (auto&[a,b,c]:t) {
        cin >> a >> b >> c;
        g[--a].pb({--b,c});
    }
    
    // 距離が同じなら、最後の追加する数が小さい方を優先すれば、そっちが先に到着するのでは？
    // 分岐から近い、数が違うポイントでの大小が優先される
    // 最初に最短距離のみのグラフを作って、後から数優先のDFS?
    // 違ったら、小さい方を最後まで掘るけど、
    // 同じなら同時に掘らなきゃダメ
    // 分岐していても、そこまでが同じなら、同時に掘らなくてはいけない

    // ダイクストラ
    // 距離
    vi d(n,n);
    // {距離,位置}
    priority_queue<pii,v<pii>,greater<>> q;
    q.push({d[0]=0,0});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (d[pos]<dist) continue;
        for (auto[nxt,c]:g[pos]) {
            if (chmin(d[nxt],dist+1)) q.push({d[nxt],nxt});
        }
    }

    // 最短距離のみのグラフ
    v<v<pii>> gg(n);
    for (auto[a,b,c]:t) {
        if (d[a]+1!=d[b]) continue;
        gg[a].pb({c,b});
    }

    v<mint> ans(n);
    ans[0]=0;
    // 最初にたどり着いたのが最小スコアとなる
    // 初回フラグ
    vb bb(n,0);
    int cnt=0;
    // {高さ,スコア,親のスコア}の順位
    map<tuple<int,int,int>,int> mp;
    // ↑これだと完璧じゃないけど、ACになった
    // これらが一致すれば、それまでのルートが完全に一致するとは限らない

    // {親の順位,最後に通る数,位置,親}
    priority_queue<tuple<int,int,int,int>,v<tuple<int,int,int,int>>,greater<>> qq;
    qq.push({0,0,0,0});
    while (!qq.empty()) {
        auto[pp,cc,pos,par]=qq.top();
        qq.pop();
        if (bb[pos]) continue;
        bb[pos]=1;
        ans[pos]=ans[par]*10+cc;
        tuple<int,int,int> p={d[pos],ans[pos].val(),ans[par].val()};
        if (!mp[p]) mp[p]=++cnt;
        for (auto[c,nxt]:gg[pos]) qq.push({mp[p],c,nxt,pos});
    }
    rep1(i,n-1) print(ans[i].val());

    return 0;
}

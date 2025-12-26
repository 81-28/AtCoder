// http://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


v<pii> nxp(pii p) {
    v<pii> res(6);
    res[0]={p.f-1,p.s};
    res[1]={p.f+1,p.s};
    res[2]={p.f,p.s-1};
    res[3]={p.f,p.s+1};
    if (p.f&1) {
        res[4]={p.f-1,p.s+1};
        res[5]={p.f+1,p.s+1};
    } else {
        res[4]={p.f-1,p.s-1};
        res[5]={p.f+1,p.s-1};
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int w,h;
    cin >> w >> h;
    vvi g(h+2,vi(w+2));
    rep1(i,h)rep1(j,w) cin >> g[i][j];
    // 六角形グリッドをBFS
    queue<pii> q;
    vvb b(h+2,vb(w+2,0));
    q.push({0,0});
    b[0][0]=1;
    while (!q.empty()) {
        pii pos=q.front();
        q.pop();
        for (auto[x,y]:nxp(pos)) {
            if (OutOfGrid({x,y},{h+2,w+2})) continue;
            if (!g[x][y] && !b[x][y]) {
                b[x][y]=1;
                q.push({x,y});
            }
        }
    }
    // 建物に隣接マスが外側の場合、外壁である
    int ans=0;
    rep1(i,h)rep1(j,w) {
        if (b[i][j]) continue;
        for (auto[x,y]:nxp({i,j})) ans+=b[x][y];
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc315/tasks/abc315_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(n);
    rep(i,n) {
        int c;
        cin >> c;
        rep(j,c) {
            int p;
            cin >> p;
            --p;
            g[i].pb(p);
        }
    }
    // 逆ダイクストラ法？
    // 一番遠い距離が採用され、その間を適切に埋める
    // 更新が多く発生する可能性もあるので、計算量が大きくなる
    // {距離,idx}
    v<pii> d(n);
    rep(i,n) d[i]={-1,i};
    // {距離,idx}
    priority_queue<pii> q;
    d[0].f=0;
    q.push({d[0].f,0});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (dist<d[pos].f) continue;
        for (int nxt:g[pos]) {
            if (chmax(d[nxt].f,dist+1)) q.push({d[nxt].f,nxt});
        }
    }
    sort(rall(d));
    rep(i,n) {
        if (d[i].f==0) break;
        cout<<d[i].s+1<<' ';
    }
    cout<<endl;

    return 0;
}

// https://atcoder.jp/contests/abc301/tasks/abc301_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int popcount(int n) {
    int res=0;
    while (n) {
        res+=n&1;
        n>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,t;
    cin >> h >> w >> t;
    v<string> a(h);
    cin >> a;
    pii st,go;
    v<pii> p;
    v<v<bool>> b(h,v<bool>(w,0));
    rep(i,h)rep(j,w) {
        if (a[i][j]=='S') st={i,j};
        if (a[i][j]=='G') go={i,j};
        if (a[i][j]=='o') p.pb({i,j});
        if (a[i][j]=='#') b[i][j]=1;
    }
    p.insert(p.begin(),st);
    p.pb(go);
    int n=p.size();

    constexpr int inf=INT_MAX/2;
    // dist[i][j]:iとjの距離
    vvi dist(n,vi(n));
    rep(i,n-1) {
        queue<pii> q;
        vvi d(h,vi(w,inf));
        auto&[x,y]=p[i];
        q.push(p[i]);
        d[x][y]=0;
        while (!q.empty()) {
            pii pos=q.front();
            q.pop();
            rep(k,4) {
                auto[nx,ny]=pos+dir[k];
                if (nx<0||h<=nx || ny<0||w<=ny) continue;
                if (b[nx][ny]) continue;
                if (chmin(d[nx][ny],d[pos.f][pos.s]+1)) q.push({nx,ny});
            }
        }
        for (int j=i; j<n; ++j) {
            auto&[xx,yy]=p[j];
            dist[i][j]=dist[j][i]=d[xx][yy];
        }
    }

    // dp[i][j]:頂点iにいて、訪問状態jになる最短距離
    // (j>>k)&1:頂点kが訪問済みかどうか
    vvi dp(n,vi(1<<n,inf));
    dp[0][1]=0;
    rep(i,1<<n)rep(j,n)rep(k,n) {
        chmin(dp[k][i|(1<<k)],dp[j][i]+dist[j][k]);
    }
    int ans=1;
    rep(i,1<<n) {
        if (dp[n-1][i]<=t) chmax(ans,popcount(i));
    }
    print(ans-2);

    return 0;
}

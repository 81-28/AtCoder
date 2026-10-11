// https://atcoder.jp/contests/abc479/tasks/abc479_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(n);
    v<pii> p(n-1);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    // 頂点0を根とする
    // 根からの距離
    vi d(n,n);
    queue<int> q;
    vi par(n,-1);
    d[0]=0;
    q.push(0);
    // 子
    vvi c(n);
    priority_queue<pii> qq;
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (chmin(d[nxt],d[pos]+1)) {
                q.push(nxt);
                par[nxt]=pos;
                c[pos].pb(nxt);
                qq.push({d[nxt],nxt});
            }
        }
    }
    // その点以下の部分木の大きさ
    // 距離が遠いところから順に加算
    vi sm(n,1);
    while (!qq.empty()) {
        auto[dep,pos]=qq.top();
        qq.pop();
        sm[par[pos]]+=sm[pos];
    }
    // 答えを累積和とし、根から順に足すことにする
    vi x(n,0);
    rep1(i,n-1) {
        auto[a,b]=p[i-1];
        if (d[a]<d[b]) {
            int tmp=a;
            a=b;
            b=tmp;
        }
        // 該当部分に一括で加算
        int sma=sm[a];
        int smb=n-sma;
        if (sma<smb) {
            x[0]+=i;
            x[a]-=i;
        } else {
            x[a]+=i;
        }
    }
    // 累積和の計算
    q.push(0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:c[pos]) {
            x[nxt]+=x[pos];
            q.push(nxt);
        }
    }
    print(x);

    return 0;
}

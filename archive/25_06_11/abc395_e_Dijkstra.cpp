// https://atcoder.jp/contests/abc395/tasks/abc395_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<class T> constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m,x;
    cin >> n >> m >> x;
    v<vvll> g(2,vvll(n+1));
    rep(i,m) {
        pll p;
        cin >> p;
        g[0][p.f].pb(p.s);
        g[1][p.s].pb(p.f);
    }
    // cost[i][j]:表裏i位置jへ来る最小コスト
    vvll cost(2,vll(n+1,LLONG_MAX));
    cost[0][1]=0;
    // q:{距離,表裏,位置}
    priority_queue<tuple<ll,bool,ll>,v<tuple<ll,bool,ll>>,greater<>> q;
    q.push({0,0,1});
    while (!q.empty()) {
        auto [c,fl,pos]=q.top();
        q.pop();
        if (c>cost[fl][pos]) continue;
        // 表裏切替
        if (chmin(cost[!fl][pos],c+x)) q.push({cost[!fl][pos],!fl,pos});
        // 同じ面で移動
        for (ll nxt:g[fl][pos]) {
            if (chmin(cost[fl][nxt],c+1)) q.push({cost[fl][nxt],fl,nxt});
        }
    }
    print(min(cost[0][n],cost[1][n]));

    return 0;
}

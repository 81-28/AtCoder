// http://atcoder.jp/contests/joi2025yo2/tasks/joi2025_yo2_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    cin >> n >> x;
    v<pii> p(n);
    rep(i,n) cin >> p[i].f;
    vvi g(n);
    // ボールiを落とすのに必要な集中力
    vi ans(n,INF);
    queue<int> q;
    rep(i,n) {
        auto&[a,pr]=p[i];
        cin >> pr;
        --pr;
        if (pr==-2) {
            ans[i]=a;
            q.push(i);
        } else g[pr].pb(i);
    }
    // 分岐はするが、合流はしない
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        int a=ans[pos];
        for (int nxt:g[pos]) {
            ans[nxt]=p[nxt].f+a;
            q.push(nxt);
        }
    }
    int mx=-1;
    rep(i,n) {
        if (ans[i]<=x) mx=i+1;
    }
    print(mx);

    return 0;
}

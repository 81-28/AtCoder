// https://atcoder.jp/contests/abc190/tasks/abc190_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m,k;
    cin >> n >> m;
    v<pii> p(m);
    for (auto&[a,b]:p) cin >> a >> b;
    cin >> k;
    v<pii> q(k);
    for (auto&[c,d]:q) cin >> c >> d;
    int mx=1<<k;
    int ans=0;
    rep(i,mx) {
        vb b(n+1,0);
        rep(j,k) {
            if ((i>>j)&1) b[q[j].f]=1;
            else b[q[j].s]=1;
        }
        int res=0;
        rep(j,m) {
            if (b[p[j].f] && b[p[j].s]) ++res;
        }
        chmax(ans,res);
    }
    print(ans);

    return 0;
}

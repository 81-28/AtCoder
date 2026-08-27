// https://atcoder.jp/contests/abc188/tasks/abc188_e

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max();
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    vvi g(n);
    while (m--) {
        int x,y;
        cin >> x >> y;
        g[--y].pb(--x);
    }
    vi mi(n,INF);
    int ans=-INF;
    rep(i,n) {
        for (int prev:g[i]) chmin(mi[i],mi[prev]);
        chmax(ans,a[i]-mi[i]);
        chmin(mi[i],a[i]);
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc474/tasks/abc474_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


void solve() {
    int n;
    cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    int mi=INF;
    int sm=0;
    vi d(n);
    rep(i,n) {
        chmin(mi,a[i]);
        sm+=b[i];
        d[i]=a[i]-b[i];
    }
    sort(all(d));
    int ans=INF;
    int lim=(n+1)/2;
    int add=0;
    rep(i,lim+1) {
        chmin(ans,sm+add+max(0LL,n-2*i)*mi);
        if (i<lim) add+=d[i];
    }
    print(ans);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

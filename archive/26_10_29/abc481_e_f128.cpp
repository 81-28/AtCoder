// https://atcoder.jp/contests/abc481/tasks/abc481_e

#include<bits/stdc++.h>
using namespace std;

using f128=float128_t;
const f128 PI=acos(f128(-1));
template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


void solve() {
    int n;
    cin >> n;
    v<f128> d(n);
    for (f128&t:d) {
        int x,y;
        cin >> x >> y;
        t=atan2(f128(y),f128(x));
        if (t<0) t+=2*PI;
    }
    sort(all(d));
    rep(i,n) d.pb(d[i]+2*PI);

    int ans=0,r=0;
    rep(l,n) {
        // auto it=lower_bound(all(d),d[l]+PI);
        // chmax(ans,int(it-d.begin()-l));
        while (r<l+n && d[r]-d[l]<PI) ++r;
        chmax(ans,r-l);
    }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// https://atcoder.jp/contests/abc481/tasks/abc481_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ld=long double;
template<typename T>
using v=vector<T>;
using pid=pair<int,ld>;
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
    v<pid> a(n);
    for (auto&[q,t]:a) {
        int x,y;
        cin >> x >> y;

        // 象限 [0,4)
        if (x>0 && y>=0) q=0;
        else if (x<=0 && y>0) q=1;
        else if (x<0 && y<=0) q=2;
        else q=3;

        // 象限内の角度 [0,PI/2)
        t=(q&1) ? atan2l(abs(x),abs(y)) : atan2l(abs(y),abs(x));
    }

    sort(all(a));
    rep(i,n) a.pb({a[i].first+4,a[i].second});

    int ans=0,r=0;
    rep(l,n) {
        pid lim={a[l].first+2,a[l].second};
        while (r<l+n && a[r]<lim) ++r;
        chmax(ans,r-l);
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

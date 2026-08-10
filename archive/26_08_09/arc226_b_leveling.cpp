// https://atcoder.jp/contests/arc226/tasks/arc226_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;
        vector<ll> a(m);
        for (ll&v:a) cin >> v;
        ll ans=0,cnt=0;
        // 水が同じ高さになるようなイメージ
        for (ll i=m-1; i>=0; --i) {
            cnt=cnt*2+a[i];
            ll need=(cnt+n-1)/n;
            ans=max(ans,need*(1LL<<i));
        }
        cout<<ans<<'\n';
    }

    return 0;
}

// https://atcoder.jp/contests/arc229/tasks/arc229_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(rall(a));
    int h=a[0],t=a[1];
    vi res={h};
    vi e,o;
    for (int i=2; i<n; ++i) {
        if (a[i]&1) o.pb(a[i]);
        else e.pb(a[i]);
    }
    int oo=o.size();
    int ee=e.size();
    int l=min(oo,ee);
    if (h&1) {
        rep(i,l) {
            res.pb(e[i]);
            res.pb(o[i]);
        }
    } else {
        rep(i,l) {
            res.pb(o[i]);
            res.pb(e[i]);
        }
    }
    if (ee<oo) {
        for (int i=l; i<oo; ++i) res.pb(o[i]);
    } else {
        for (int i=l; i<ee; ++i) res.pb(e[i]);
    }
    res.pb(t);
    int ans=0;
    rep(i,n-1) ans+=(res[i]+res[i+1])/2;
    print(ans);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

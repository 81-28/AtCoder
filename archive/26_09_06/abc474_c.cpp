// https://atcoder.jp/contests/abc474/tasks/abc474_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
#define rrep(i,n) for(int i=(int)(n-1);i>=0;--i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi p(n),a(q);
    cin >> p >> a;
    vb b(n+1,0);
    vi ans;
    rrep(i,q) {
        if (b[a[i]]) continue;
        b[a[i]]=1;
        ans.pb(a[i]);
    }
    rrep(i,n) {
        if (b[p[i]]) continue;
        b[p[i]]=1;
        ans.pb(p[i]);
    }
    rrep(i,n) cout<<ans[i]<<' ';

    return 0;
}

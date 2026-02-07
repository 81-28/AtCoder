// https://atcoder.jp/contests/abc444/tasks/abc444_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(all(a));
    int mx=2e5;
    vi ans(mx+20,0);
    rep(i,mx) {
        auto it=lower_bound(all(a),i+1);
        int d=a.end()-it;
        for (int j=i; d; ++j) {
            int sm=ans[j]+d;
            ans[j]=sm%10;
            d=sm/10;
        }
    }
    bool f=1;
    for (int i=mx+20; i>=0; --i) {
        if (f && ans[i]==0) continue;
        f=0;
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}

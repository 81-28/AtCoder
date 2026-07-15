// https://atcoder.jp/contests/abc199/tasks/abc199_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,q;
    string s;
    cin >> n >> s >> q;
    bool f=0;
    vi idx(n*2);
    rep(i,n*2) idx[i]=i;
    while (q--) {
        int t,a,b;
        cin >> t >> a >> b;
        if (t&1) {
            --a,--b;
            if (f) {
                if (a<n) a+=n;
                else a-=n;
                if (b<n) b+=n;
                else b-=n;
            }
            int tmp=idx[a];
            idx[a]=idx[b];
            idx[b]=tmp;
        } else f^=1;
    }
    rep(i,n) cout<<s[idx[i+n*f]];
    rep(i,n) cout<<s[idx[i+n*(!f)]];
    cout<<endl;

    return 0;
}

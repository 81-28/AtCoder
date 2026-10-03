// https://atcoder.jp/contests/abc478/tasks/abc478_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    map<int,v<pii>> m;
    while (q--) {
        int l,r,x;
        cin >> l >> r >> x;
        m[x].pb({--l,r});
    }
    vi sm(n+1,0);
    for (auto&[x,vec]:m) {
        sort(all(vec));
        v<pii> p;
        for (auto[l,r]:vec) {
            if (p.size() && p.back().second>=l) {
                chmax(p.back().second,r);
                continue;
            }
            p.pb({l,r});
        }
        for (auto[l,r]:p) ++sm[l],--sm[r];
    }
    rep(i,n) {
        cout<<sm[i]<<' ';
        sm[i+1]+=sm[i];
    }
    cout<<endl;

    return 0;
}

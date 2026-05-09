// https://atcoder.jp/contests/abc457/tasks/abc457_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<pii> p(m);
    // m?[i]:iから始まるもので、もう片方の端
    map<int,vi> ml,mr;
    map<pii,int> mp;
    rep(i,m) {
        auto&[l,r]=p[i];
        cin >> l >> r;
        ml[l].pb(r);
        mr[r].pb(l);
        ++mp[{l,r}];
    }
    sort(all(p));
    for (auto&[val,vec]:ml) sort(all(vec));
    for (auto&[val,vec]:mr) sort(all(vec));
    int q;
    cin >> q;
    while (q--) {
        int s,t;
        cin >> s >> t;
        if (mp[{s,t}]>=2) {
            YesNo(1);
            continue;
        }
        if (mp[{s,t}]==0) {
            auto itl=upper_bound(all(ml[s]),t);
            if (itl==ml[s].begin()) {
                YesNo(0);
                continue;
            }
            --itl;
            auto itr=lower_bound(all(mr[t]),s);
            if (itr==mr[t].end()) {
                YesNo(0);
                continue;
            }
            YesNo(*itl+1>=*itr);
        } else {
            // 1
            int cnt=0;
            auto itl=lower_bound(all(p),pii(s,0));
            auto itr=lower_bound(all(p),pii(t+1,0));
            for (auto it=itl;it!=itr;++it) {
                auto[l,r]=*it;
                if (s<=l && r<=t) ++cnt;
                if (cnt>1) break;
            }
            YesNo(cnt>1);
        }
    }

    return 0;
}

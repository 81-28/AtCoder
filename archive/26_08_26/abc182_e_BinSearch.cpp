// https://atcoder.jp/contests/abc182/tasks/abc182_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n,m;
    cin >> h >> w >> n >> m;
    // {位置,光かどうか}
    v<v<pair<int,bool>>> r(h),c(w);
    while (n--) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        r[x].pb({y,1});
        c[y].pb({x,1});
    }
    while (m--) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        r[x].pb({y,0});
        c[y].pb({x,0});
    }
    rep(i,h) sort(all(r[i]));
    rep(j,w) sort(all(c[j]));
    int ans=0;
    rep(i,h)rep(j,w) {
        auto itr=lower_bound(all(r[i]),pair<int,bool>(j,0));
        if (itr!=r[i].end()) {
            if (itr->second) {
                ++ans;
                continue;
            }
            if (itr->first==j) continue;
        }
        if (itr!=r[i].begin()) {
            --itr;
            if (itr->second) {
                ++ans;
                continue;
            }
        }
        auto itc=lower_bound(all(c[j]),pair<int,bool>(i,0));
        if (itc!=c[j].end()) {
            if (itc->second) {
                ++ans;
                continue;
            }
            if (itc->first==i) continue;
        }
        if (itc!=c[j].begin()) {
            --itc;
            if (itc->second) {
                ++ans;
                continue;
            }
        }
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc431/tasks/abc431_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    multiset<int> hs,bs;
    rep(i,n) {
        int h;
        cin >> h;
        hs.insert(h);
    }
    rep(i,m) {
        int b;
        cin >> b;
        bs.insert(b);
    }
    rep(i,k) {
        int h=*hs.begin();
        auto it=bs.lower_bound(h);
        if (it!=bs.end()) {
            bs.erase(it);
            hs.erase(hs.begin());
        } else {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

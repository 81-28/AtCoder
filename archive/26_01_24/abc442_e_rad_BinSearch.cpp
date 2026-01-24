// https://atcoder.jp/contests/abc442/tasks/abc442_e

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
constexpr ld PI=acos(-1);
template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // rad : [-PI/2 , 3PI/2)
    v<ld> d(n);
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        d[i]=atan((ld)y/x);
        if (x<0) d[i]+=PI;
    }
    v<ld> dd=d;
    sort(all(dd));

    while (q--) {
        int a,b;
        cin >> a >> b;
        ld rada=d[--a],radb=d[--b];
        auto ita=upper_bound(all(dd),rada);
        auto itb=lower_bound(all(dd),radb);
        if (ita>itb) print(ita-itb);
        else print(n-(itb-ita));
    }

    return 0;
}

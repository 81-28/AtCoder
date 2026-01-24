// https://atcoder.jp/contests/abc442/tasks/abc442_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ld=long double;
template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


constexpr ld pi=acos(-1);

using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // {x,y,rad}
    v<tuple<int,int,ld>> t(n);
    // rad : [-pi/2 , 3pi/2)
    v<ld> d;
    rep(i,n) {
        auto&[x,y,rad]=t[i];
        cin >> x >> y;
        rad=atan((ld)y/x);
        if (x<0) rad+=pi;
        d.pb(rad);
    }
    sort(all(d));
    v<ld> dd=d;
    uniq(dd);
    unordered_map<ld,int> mp;
    int m=0;
    for (ld rad:dd) mp[rad]=m++;
    segtree<S,op,e> seg(m);
    for (ld rad:d) seg.set(mp[rad],seg.get(mp[rad])+1);

    while (q--) {
        int a,b;
        cin >> a >> b;
        auto[xa,ya,rada]=t[--a];
        auto[xb,yb,radb]=t[--b];
        int i=mp[rada],j=mp[radb];
        if (i>=j) print(seg.prod(j,i+1));
        else print(n-seg.prod(i+1,j));
    }

    return 0;
}

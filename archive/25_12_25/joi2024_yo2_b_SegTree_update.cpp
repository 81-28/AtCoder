// https://atcoder.jp/contests/joi2024yo2/tasks/joi2024_yo2_b

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define f first

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,q;
    cin >> n >> m >> q;
    v<pii> p(n);
    map<int,vi> mp;
    rep(i,n) {
        auto&[pr,a]=p[i];
        cin >> pr >> a;
        mp[a].pb(i);
    }
    v<tuple<int,int,int,int>> tu(q);
    rep(i,q) {
        auto&[t,l,r,j]=tu[i];
        cin >> t >> l >> r;
        --l;
        j=i;
    }
    sort(all(tu));

    v<S> init(n);
    rep(i,n) init[i]=p[i].f;
    segtree<S,op,e> seg(init);
    for (int i:mp[get<0>(tu[0])]) seg.set(i,p[i].f/2);
    vi ans(q);
    rep(i,q) {
        auto[t,l,r,j]=tu[i];
        ans[j]=seg.prod(l,r);
        if (i+1<q) {
            // セール商品が変わる時だけ更新(変わる回数最小化のために事前ソート)
            auto[tt,x,y,z]=tu[i+1];
            if (t==tt) continue;
            for (int k:mp[t]) seg.set(k,p[k].f);
            for (int k:mp[tt]) seg.set(k,p[k].f/2);
        }
    }
    rep(i,q) print(ans[i]);

    return 0;
}

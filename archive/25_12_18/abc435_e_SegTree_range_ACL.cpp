// https://atcoder.jp/contests/abc435/tasks/abc435_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi c;
struct S{
    int val,siz;
    S(){val=siz=0;}
    S(int v,int s){
        val=v;
        siz=s;
    }
};
using F=int;
constexpr F ID=-1;
S op(S a,S b){return {a.val+b.val,a.siz+b.siz};}
S e(){return S();}
S mapping(F f,S x){if(f!=ID)x.val=f*x.siz; return x;}
F composition(F f,F g){return f==ID?g:f;}
F id(){return ID;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    c.pb(0),c.pb(n);
    v<pii> p(q);
    for (auto&[l,r]:p) {
        cin >> l >> r;
        c.pb(--l),c.pb(r);
    }
    sort(all(c));
    uniq(c);
    int m=c.size()-1;
    unordered_map<int,int> idx;
    rep(i,m+1) idx[c[i]]=i;

    v<S> init(m);
    rep(i,m) init[i]=S(0,c[i+1]-c[i]);
    lazy_segtree<S,op,e,F,mapping,composition,id> t(init);

    int ans=n;
    for (auto[l,r]:p) {
        int i=idx[l],j=idx[r];
        ans-=(r-l)-t.prod(i,j).val;
        print(ans);
        t.apply(i,j,1);
    }

    return 0;
}

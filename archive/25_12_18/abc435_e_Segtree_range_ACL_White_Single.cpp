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


// 白の合計
// 白の幅は減らす(0で上書きする)だけなので、区間長さの情報は不要
using S=int;
using F=int;
constexpr F ID=-1;
S op(S a,S b){return a+b;}
S e(){return S();}
S mapping(F f,S x){return f==ID?x:0;}
F composition(F f,F g){return f==ID?g:f;}
F id(){return ID;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi c={0,n};
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
    rep(i,m) init[i]=S(c[i+1]-c[i]);
    lazy_segtree<S,op,e,F,mapping,composition,id> t(init);

    for (auto[l,r]:p) {
        int i=idx[l],j=idx[r];
        t.apply(i,j,0);
        print(t.all_prod());
    }

    return 0;
}

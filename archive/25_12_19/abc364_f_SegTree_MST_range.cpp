// https://atcoder.jp/contests/abc364/tasks/abc364_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return 0;}
using F=int;
constexpr F ID=-1;
S mapping(F f,S x){return (f==ID)?x:0;}
F composition(F f,F g){return f==ID?g:f;}
F id(){return ID;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<tuple<int,int,int>> t(q);
    for (auto&[c,l,r]:t) {
        cin >> l >> r >> c;
        --l;
    }
    sort(all(t));
    // s[i]:iとi+1が繋がっていない場合:1
    v<S> init(n-1,1);
    lazy_segtree<S,op,e,F,mapping,composition,id> s(init);
    int ans=0;
    for (auto[c,l,r]:t) {
        ans+=(s.prod(l,r-1)+1)*c;
        s.apply(l,r-1,0);
    }
    print(s.all_prod()?-1:ans);

    return 0;
}

// https://atcoder.jp/contests/abc477/tasks/abc477_f

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

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct S{
    int val,siz;
    S(int x,int y) {val=x,siz=y;}
    S(int x){val=x,siz=1;}
    S(){val=0,siz=0;}
};
using F=int;
S op(S a,S b) {return {a.val+b.val,a.siz+b.siz};}
S e(){return S();}
S mapping(F f,S x) {return {x.val+f*x.siz,x.siz};}
F composition(F f,F g) {return f+g;}
F id() {return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,q;
    cin >> n >> m >> q;
    v<pii> p(n);
    for (auto&[l,r]:p) {
        cin >> l >> r;
        --l;
    }
    // {行,c,d,i,加算倍率}
    v<tuple<int,int,int,int,int>> t;
    rep(i,q) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        --a,--c;
        t.pb({a,c,d,i,-1});
        t.pb({b,c,d,i,1});
    }
    sort(all(t));

    vi ans(q);
    int row=0;
    v<S> init(m,S(0));
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(init);
    // 若い行から先に処理
    for (auto[ro,c,d,i,x]:t) {
        while (row<ro) {
            auto[l,r]=p[row];
            seg.apply(l,r,1);
            ++row;
        }
        ans[i]+=x*seg.prod(c,d).val;
    }
    for (int val:ans) print(val);

    return 0;
}

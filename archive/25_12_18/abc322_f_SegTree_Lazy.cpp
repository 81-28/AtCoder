// https://atcoder.jp/contests/abc322/tasks/abc322_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// mx[i]:区間の中のiの個数の最大値
// l[i]:区間の左端のiの個数
// r[i]:区間の右端のiの個数
// siz:区間の長さ
struct S{
    int mx[2],l[2],r[2],siz;
    S(){mx[0]=mx[1]=l[0]=l[1]=r[0]=r[1]=siz=0;}
    S(bool b){
        mx[0]=l[0]=r[0]=!b;
        mx[1]=l[1]=r[1]=b;
        siz=1;
    }
};
using F=int;
S op(S a,S b){
    S res;
    rep(i,2) {
        res.mx[i]=max({a.mx[i],b.mx[i],a.r[i]+b.l[i]});
        res.l[i]=a.l[i]+(a.l[i]==a.siz?b.l[i]:0);
        res.r[i]=b.r[i]+(b.r[i]==b.siz?a.r[i]:0);
    }
    res.siz=a.siz+b.siz;
    return res;
}
S e(){return S();}
S mapping(F f,S x){
    if (!f) return x;
    S y;
    rep(i,2) {
        y.mx[i]=x.mx[!i];
        y.l[i]=x.l[!i];
        y.r[i]=x.r[!i];
    }
    y.siz=x.siz;
    return y;
}
F composition(F f,F g){return f^g;}
F id(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    v<S> init(n);
    rep(i,n) init[i]=S(s[i]-'0');
    lazy_segtree<S,op,e,F,mapping,composition,id> t(init);
    while (q--) {
        int c,l,r;
        cin >> c >> l >> r;
        if (c==1) t.apply(--l,r,1);
        else print(t.prod(--l,r).mx[1]);
    }

    return 0;
}

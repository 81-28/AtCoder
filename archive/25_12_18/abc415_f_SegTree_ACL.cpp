// https://atcoder.jp/contests/abc415/tasks/abc415_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// {左,(中央の最大),右}の{文字,数}を返し、連続最大値を返す
using S=v<pii>;
S op(S a,S b){
    int n=a.size(),m=b.size(),l=n+m;
    if (n && m && a[n-1].f==b[0].f) {
        a[n-1].s+=b[0].s;
        --l;
    }
    for (int i=n+m-l; i<m; ++i) a.pb(b[i]);
    if (l<4) return a;
    pii h=a[0],t=a[l-1];
    int mx=0;
    for (int i=1; i<l-1; ++i) chmax(mx,a[i].s);
    return {h,{0,mx},t};
}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string st;
    cin >> n >> q >> st;
    v<S> init(n);
    rep(i,n) init[i]={{st[i]-'a',1}};
    segtree<S,op,e> t(init);
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            int i;
            char x;
            cin >> i >> x;
            t.set(--i,{{x-'a',1}});
        } else {
            int l,r;
            cin >> l >> r;
            S vec=t.prod(--l,r);
            int mx=0;
            for (pii p:vec) chmax(mx,p.s);
            print(mx);
        }
    }

    return 0;
}

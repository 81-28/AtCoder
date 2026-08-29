// https://atcoder.jp/contests/abc473/tasks/abc473_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


struct S{
    int sm,mi;
};
S op(S l,S r){
    return {
        l.sm+r.sm,
        min(l.mi,l.sm+r.mi)
    };
}
S e(){return {0,0};}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> s >> q;
    v<S> init(n);
    rep(i,n) {
        if (s[i]=='A') init[i]={1,0};
        else init[i]={-1,-1};
    }
    segtree<S,op,e> t(init);

    while (q--) {
        int m;
        cin >> m;
        if (m&1) {
            int i;
            char c;
            cin >> i >> c;
            --i;
            if (c=='A') t.set(i,{1,0});
            else t.set(i,{-1,-1});
        } else {
            int l,r;
            cin >> l >> r;
            S res=t.prod(--l,r);
            YesNo(res.mi>=0);
        }
    }

    return 0;
}

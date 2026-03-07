// https://atcoder.jp/contests/abc448/tasks/abc448_c

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max()/2;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct S{
    int val;
    bool b;
    S(int x,bool y) {val=x,b=y;}
    S(int x) {val=x,b=1;}
    S() {val=INF;b=1;}
};
S op(S a,S c) {
    if (a.b) {
        if (c.b) return min(a.val,c.val);
        else return a.val;
    } else {
        if (c.b) return c.val;
        else return S();
    }
}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    v<S> init(n);
    rep(i,n) init[i]=S(a[i]);
    segtree<S,op,e> t(init);
    while (q--) {
        int k;
        cin >> k;
        vi b(k);
        rep(i,k) {
            cin >> b[i];
            --b[i];
            t.set(b[i],S(a[b[i]],0));
        }
        print(t.all_prod().val);
        rep(i,k) {
            t.set(b[i],S(a[b[i]]));
        }
    }

    return 0;
}

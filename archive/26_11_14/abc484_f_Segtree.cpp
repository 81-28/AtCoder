// https://atcoder.jp/contests/abc484/tasks/abc484_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


// -1以外が全て同じであるか
// その数値
struct S{
    bool ok;
    int num;
    S(bool b,int x) {
        ok=b;
        num=x;
    }
    S(int x) {
        ok=1;
        num=x;
    }
    S(){
        ok=1;
        num=-1;
    }
};
S op(S a,S b){
    if (!a.ok || b.num==-1) return a;
    if (!b.ok || a.num==-1) return b;
    if (a.num==b.num) return a;
    return {0,0};
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
        int m,x,y;
        cin >> m >> x >> y;
        if (m&1) t.set(--x,y);
        else YesNo(t.prod(--x,y).ok);
    }

    return 0;
}

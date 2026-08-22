// https://atcoder.jp/contests/abc472/tasks/abc472_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,q;
    cin >> n >> q;
    v<S> xx(n),yy(n),aa(n);
    vi x(n),y(n);
    int c;
    rep(i,n) {
        cin >> x[i] >> y[i];
        if (i==0) continue;
        c=x[i-1]*y[i]-x[i]*y[i-1];
        aa[i-1]=c*3;
        xx[i-1]=(x[i-1]+x[i])*c;
        yy[i-1]=(y[i-1]+y[i])*c;
    }
    c=x[n-1]*y[0]-x[0]*y[n-1];
    aa[n-1]=c*3;
    xx[n-1]=(x[n-1]+x[0])*c;
    yy[n-1]=(y[n-1]+y[0])*c;

    segtree<S,op,e> tx(xx),ty(yy),ta(aa);

    while (q--) {
        int u,v;
        cin >> u >> v;
        --u,--v;
        int a,rx,ry;
        if (u<v) {
            a=ta.prod(u,v);
            rx=tx.prod(u,v);
            ry=ty.prod(u,v);
        } else {
            a=ta.prod(u,n)+ta.prod(0,v);
            rx=tx.prod(u,n)+tx.prod(0,v);
            ry=ty.prod(u,n)+ty.prod(0,v);
        }
        c=x[v]*y[u]-x[u]*y[v];
        a+=c*3;
        rx+=(x[u]+x[v])*c;
        ry+=(y[u]+y[v])*c;
        print((ld)rx/a,(ld)ry/a);
    }

    return 0;
}

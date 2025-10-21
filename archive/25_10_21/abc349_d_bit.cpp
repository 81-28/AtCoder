// https://atcoder.jp/contests/abc349/tasks/abc349_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define pb push_back

template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,r;
    cin >> l >> r;
    int m=0;
    for (int i=60; i>=0; --i) {
        // (l[i]==0&&r[i]==1)となる最大の桁
        bool li=(l>>i)&1,ri=(r>>i)&1;
        if (ri) m|=(1LL<<i);
        if (li!=ri) break;
    }
    v<pii> ansl,ansr;
    for (int a=m-l,t=l,i=0; a; a>>=1,++i) {
        if (a&1) {
            int d=1LL<<i;
            ansl.pb({t,t+d});
            t+=d;
        }
    }
    for (int a=r-m,t=r,i=0; a; a>>=1,++i) {
        if (a&1) {
            int d=1LL<<i;
            ansr.pb({t-d,t});
            t-=d;
        }
    }
    int n=ansr.size();
    print(ansl.size()+n);
    for (pii p:ansl) print(p);
    for (int i=n-1; i>=0; --i) print(ansr[i]);

    return 0;
}

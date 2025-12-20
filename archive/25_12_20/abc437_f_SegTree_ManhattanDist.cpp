// https://atcoder.jp/contests/abc437/tasks/abc437_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
inline int ManhattanDist(const pii& a,const pii& b){return abs(a.first-b.first)+abs(a.second-b.second);}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct S{
    pii ur,ul,dr,dl;
    S(){
        ur={-INF,-INF};
        ul={-INF,INF};
        dr={INF,-INF};
        dl={INF,INF};
    }
    S(pii p) {
        ur=ul=dr=dl=p;
    }
};
S op(S a,S b){
    S res;
    res.ur = (a.ur.f+a.ur.s > b.ur.f+b.ur.s) ? a.ur:b.ur;
    res.ul = (a.ul.f-a.ul.s > b.ul.f-b.ul.s) ? a.ul:b.ul;
    res.dr = (-a.dr.f+a.dr.s > -b.dr.f+b.dr.s) ? a.dr:b.dr;
    res.dl = (-a.dl.f-a.dl.s > -b.dl.f-b.dl.s) ? a.dl:b.dl;
    return res;
}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<S> init(n);
    rep(i,n) {
        pii p;
        cin >> p;
        init[i]=S(p);
    }
    segtree<S,op,e> t(init);

    while (q--) {
        int m;
        cin >> m;
        pii p;
        if (m==1) {
            int i;
            cin >> i >> p;
            t.set(--i,S(p));
        } else {
            int l,r;
            cin >> l >> r >> p;
            S res=t.prod(--l,r);
            int ans=0;
            chmax(ans,ManhattanDist(p,res.ur));
            chmax(ans,ManhattanDist(p,res.ul));
            chmax(ans,ManhattanDist(p,res.dr));
            chmax(ans,ManhattanDist(p,res.dl));
            print(ans);
        }
    }

    return 0;
}

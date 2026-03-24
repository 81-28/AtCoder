// https://atcoder.jp/contests/abc275/tasks/abc275_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first
#define s second
// pairの足し算
template<typename F,typename S> pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pair同士の引き算
template<typename F,typename S> pair<F,S> operator-(const pair<F,S>& a,const pair<F,S>& b){return{a.f-b.f,a.s-b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<string> st(9);
    cin >> st;
    v<pii> p;
    rep(i,9)rep(j,9) {
        if (st[i][j]=='#') p.pb({i,j});
    }
    int n=p.size();
    int ans=0;
    rep(i,n-1)for(int j=i+1; j<n; ++j) {
        auto[vx,vy]=p[j]-p[i];
        pii vec={-vy,vx};
        pii pi=p[i]+vec,pj=p[j]+vec;
        if (OutOfGrid(pi,{9,9})) continue;
        if (st[pi.f][pi.s]=='.') continue;
        if (OutOfGrid(pj,{9,9})) continue;
        if (st[pj.f][pj.s]=='.') continue;
        ++ans;
    }
    print(ans/2);

    return 0;
}

// https://atcoder.jp/contests/joisc2013-day1/tasks/joisc2013_joi_poster

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pair同士の引き算
template<typename F,typename S> pair<F,S> operator-(const pair<F,S>& a,const pair<F,S>& b){return{a.f-b.f,a.s-b.s};}

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int dist2(pii p,pii q) {
    auto[x,y]=q-p;
    return x*x+y*y;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,w,h;
    cin >> n >> w >> h;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    int ans=0;
    rep(a,n-1)for(int c=a+1; c<n; ++c) {
        rep(b,n) {
            if (b==a || b==c) continue;
            rep(d,n) {
                if (d==a || d==c || d==b) continue;
                pii p0=p[a],p1=p[c];
                int r0=dist2(p0,p[b]),r1=dist2(p1,p[d]);
                // 2円がそれぞれ、はみ出さないか判定
                if (p0.f*p0.f<r0) continue;
                if ((w-p0.f)*(w-p0.f)<r0) continue;
                if (p0.s*p0.s<r0) continue;
                if ((h-p0.s)*(h-p0.s)<r0) continue;
                if (p1.f*p1.f<r1) continue;
                if ((w-p1.f)*(w-p1.f)<r1) continue;
                if (p1.s*p1.s<r1) continue;
                if ((h-p1.s)*(h-p1.s)<r1) continue;
                int dst=dist2(p0,p1);
                // 円の包含判定
                // doubleではWA
                if (dst+r0+2*sqrt((ld)dst*r0)<r1 || dst+r1+2*sqrt((ld)dst*r1)<r0) ++ans;
            }
        }
    }
    print(ans);

    return 0;
}

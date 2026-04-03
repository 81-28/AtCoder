// https://atcoder.jp/contests/abc266/tasks/abc266_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<pii> p(4);
    rep(i,4) cin >> p[i];
    rep(i,4) {
        auto[ax,ay]=p[i];
        auto[bx,by]=p[(i+1)%4];
        auto[cx,cy]=p[(i+2)%4];
        int vax=ax-bx,vay=ay-by;
        int vcx=cx-bx,vcy=cy-by;
        if (vax*vcy-vay*vcx>0) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

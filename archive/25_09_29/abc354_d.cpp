// https://atcoder.jp/contests/abc354/tasks/abc354_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int sx[4]={0,3,6,7},sy[2]={0,4};
int sxy[4][2]={{0,0},{0,2},{0,3},{0,3}};
int s(const int& x,const int& xr,const int& y,const int& yr) {
    return 8*x*y + sx[xr]*y + sy[yr]*x + sxy[xr][yr];
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ad=1e9;
    a+=ad,b+=ad,c+=ad,d+=ad;
    int ar=a%4,br=b%2,cr=c%4,dr=d%2;
    a/=4,b/=2,c/=4,d/=2;
    int ans=s(a,ar,b,br)+s(c,cr,d,dr)-s(a,ar,d,dr)-s(c,cr,b,br);
    print(ans);

    return 0;
}

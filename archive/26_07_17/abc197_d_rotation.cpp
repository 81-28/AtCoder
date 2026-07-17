// https://atcoder.jp/contests/abc197/tasks/abc197_d

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
const ld PI=acos(-1);
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    vi x(2),y(2);
    cin >> n;
    rep(i,2) cin >> x[i] >> y[i];
    ld mx=sum(x)/2.0,my=sum(y)/2.0;
    ld dx=x[0]-mx,dy=y[0]-my;
    ld theta=2*PI/n;
    ld nx=dx*cos(theta)-dy*sin(theta);
    ld ny=dx*sin(theta)+dy*cos(theta);
    print(nx+mx,ny+my);

    return 0;
}

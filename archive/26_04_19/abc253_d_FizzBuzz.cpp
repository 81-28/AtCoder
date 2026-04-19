// https://atcoder.jp/contests/abc253/tasks/abc253_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    cin >> n >> a >> b;
    int ans=0;
    int l=1,r=n/l;
    ans+=r*(r+1)/2*l;
    l=a,r=n/l;
    ans-=r*(r+1)/2*l;
    l=b,r=n/l;
    ans-=r*(r+1)/2*l;
    l=lcm(a,b),r=n/l;
    ans+=r*(r+1)/2*l;
    print(ans);

    return 0;
}

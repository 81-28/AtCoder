// https://atcoder.jp/contests/abc428/tasks/abc428_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int s,a,b,x;
    cin >> s >> a >> b >> x;
    int sm=a+b;
    int r=x%sm;
    int ans=s*a*(x/sm);
    if (r<=a) ans+=s*r;
    else ans+=s*a;
    print(ans);

    return 0;
}

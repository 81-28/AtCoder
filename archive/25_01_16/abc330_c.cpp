// https://atcoder.jp/contests/abc330/tasks/abc330_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll d;
    cin >> d;
    ll r = sqrt(d);
    ll ans = LLONG_MAX;
    ll dd,y;
    for (ll x=0; x<=r; x++) {
        dd = d-x*x;
        y = sqrt(dd);
        ans = min(ans,d-x*x-y*y);
        ans = min(ans,x*x+(y+1)*(y+1)-d);
    }
    print(ans);

    return 0;
}

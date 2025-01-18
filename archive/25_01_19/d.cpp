// https://atcoder.jp/contests/abc389/tasks/abc389_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ld r;
    cin >> r;
    ll l = (sqrt(r*r - 0.5*0.5)-0.5);
    ll ans = l*4 + 1;
    for (ll x=1; x<=l; x++) {
        ans += (ll)(sqrt(r*r - (0.5+x)*(0.5+x))-0.5)*4;
    }
    print(ans);

    return 0;
}

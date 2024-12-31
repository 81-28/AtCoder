// https://atcoder.jp/contests/abc334/tasks/abc334_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll a,m,l,r;
    cin >> a >> m >> l >> r;
    if (l<=a && a<=r) print((r-a)/m - (l-a)/m + 1);
    if (a<l) print((r-a)/m - (l-a-1)/m);
    if (r<a) print((a-l)/m - (a-r-1)/m);

    return 0;
}

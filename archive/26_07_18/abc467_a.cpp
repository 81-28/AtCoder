// https://atcoder.jp/contests/abc467/tasks/abc467_a

#include<bits/stdc++.h>
using namespace std;

using ld=long double;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    ld h,w;
    cin >> h >> w;
    h/=100;
    ld b=w/h/h;
    YesNo(b>=25);

    return 0;
}

// https://atcoder.jp/contests/abc449/tasks/abc449_a

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
const ld PI=acos(-1);

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int d;
    cin >> d;
    ld r=d/2.0;
    cout<<fixed<<setprecision(16);
    print(PI*r*r);

    return 0;
}

// https://atcoder.jp/contests/abc259/tasks/abc259_b

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
const ld PI=acos(-1);

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int a,b,d;
    cin >> a >> b >> d;
    ld theta=PI*d/180;
    ld aa=a*cos(theta)-b*sin(theta);
    ld bb=a*sin(theta)+b*cos(theta);
    print(aa,bb);

    return 0;
}

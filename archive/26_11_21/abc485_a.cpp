// https://atcoder.jp/contests/abc485/tasks/abc485_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    YesNo((a<0&&b<0)||(0<a&&0<b));

    return 0;
}

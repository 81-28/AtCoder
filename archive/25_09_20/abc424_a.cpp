// https://atcoder.jp/contests/abc424/tasks/abc424_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c;
    cin >> a >> b >> c;
    bool ok=0;
    if (a==b) ok=1;
    if (b==c) ok=1;
    if (c==a) ok=1;
    YesNo(ok);

    return 0;
}

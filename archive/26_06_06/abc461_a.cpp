// https://atcoder.jp/contests/abc461/tasks/abc461_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,d;
    cin >> a >> d;
    YesNo(d>=a);

    return 0;
}

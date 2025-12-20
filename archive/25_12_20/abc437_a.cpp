// https://atcoder.jp/contests/abc437/tasks/abc437_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    print(a*12+b);

    return 0;
}

// https://atcoder.jp/contests/abc423/tasks/abc423_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,c;
    cin >> x >> c;
    int r=x/(1000+c);
    print(1000*r);

    return 0;
}

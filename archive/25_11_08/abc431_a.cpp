// https://atcoder.jp/contests/abc431/tasks/abc431_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,b;
    cin >> h >> b;
    print(max(h-b,0));

    return 0;
}

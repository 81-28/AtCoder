// https://atcoder.jp/contests/abc454/tasks/abc454_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,r;
    cin >> l >> r;
    print(r-l+1);

    return 0;
}

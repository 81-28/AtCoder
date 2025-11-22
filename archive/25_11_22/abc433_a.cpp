// https://atcoder.jp/contests/abc433/tasks/abc433_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y,z;
    cin >> x >> y >> z;
    if (x<=y) {
        YesNo(0);
    } else {
        int d=x-y;
        if (d%(z-1)) YesNo(0);
        else YesNo((d/(z-1))>=y);
    }

    return 0;
}

// https://atcoder.jp/contests/abc463/tasks/abc463_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y;
    cin >> x >> y;
    if (x%16) {
        YesNo(0);
        return 0;
    }
    YesNo(x/16*9==y);

    return 0;
}

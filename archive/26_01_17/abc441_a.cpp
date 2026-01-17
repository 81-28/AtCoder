// https://atcoder.jp/contests/abc441/tasks/abc441_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int p,q,x,y;
    cin >> p >> q >> x >> y;
    YesNo(p<=x&&x<p+100 && q<=y&&y<q+100);

    return 0;
}

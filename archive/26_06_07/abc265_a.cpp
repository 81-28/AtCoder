// https://atcoder.jp/contests/abc265/tasks/abc265_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y,n;
    cin >> x >> y >> n;
    if (x*3<=y) print(x*n);
    else print(n/3*y+n%3*x);

    return 0;
}

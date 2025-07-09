// https://atcoder.jp/contests/abc214/tasks/abc214_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    if (n<=125) print(4);
    else if (n<=211) print(6);
    else print(8);

    return 0;
}

// https://atcoder.jp/contests/abc269/tasks/abc269_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    print((a+b)*(c-d));
    print("Takahashi");

    return 0;
}

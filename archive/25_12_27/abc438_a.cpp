// https://atcoder.jp/contests/abc438/tasks/abc438_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int d,f;
    cin >> d >> f;
    int ans=(7+f-d%7)%7;
    print(ans==0?7:ans);

    return 0;
}

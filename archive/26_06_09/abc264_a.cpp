// https://atcoder.jp/contests/abc264/tasks/abc264_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s="atcoder";
    int l,r;
    cin >> l >> r;
    --l;
    print(s.substr(l,r-l));

    return 0;
}

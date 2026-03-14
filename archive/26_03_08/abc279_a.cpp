// https://atcoder.jp/contests/abc279/tasks/abc279_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int ans=0;
    for(char c:s) ans+=(c=='w')+1;
    print(ans);

    return 0;
}

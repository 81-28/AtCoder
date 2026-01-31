// https://atcoder.jp/contests/abc443/tasks/abc443_a

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    s.pb('s');
    print(s);

    return 0;
}

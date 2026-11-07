// https://atcoder.jp/contests/abc483/tasks/abc483_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    print((n+1)/2);

    return 0;
}

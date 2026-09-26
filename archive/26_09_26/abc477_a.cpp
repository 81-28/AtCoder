// https://atcoder.jp/contests/abc477/tasks/abc477_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    char c;
    cin >> c;
    if (c=='B') print('Y');
    if (c=='Y') print('R');
    if (c=='R') print('B');

    return 0;
}

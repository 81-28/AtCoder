// https://atcoder.jp/contests/abc264/tasks/abc264_b

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int r,c;
    cin >> r >> c;
    if (r+c>16) r=16-r,c=16-c;
    print(min(r,c)&1?"black":"white");

    return 0;
}

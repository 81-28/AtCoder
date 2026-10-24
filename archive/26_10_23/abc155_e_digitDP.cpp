// https://atcoder.jp/contests/abc155/tasks/abc155_e

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string n;
    cin >> n;
    // あらゆる支払方法の最小枚数
    // 直前の位で、繰り上がり、なし / あり
    int dp[]={0,1},dpn[2];
    for (int i=n.size()-1; i>=0; --i) {
        int x=n[i]-'0';
        dpn[0]=min(dp[0]+x,dp[1]+x+1);
        dpn[1]=min(dp[0]+10-x,dp[1]+9-x);
        dp[0]=dpn[0],dp[1]=dpn[1];
    }
    print(min(dp[0],dp[1]+1));

    return 0;
}

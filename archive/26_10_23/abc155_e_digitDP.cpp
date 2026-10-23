// https://atcoder.jp/contests/abc155/tasks/abc155_e

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

#define f first
#define s second

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string n;
    cin >> n;
    // あらゆる支払方法の最小枚数
    // 直前の位で、繰り上がり、なし / あり
    pii dp={0,1};
    for (int i=n.size()-1; i>=0; --i) {
        int x=n[i]-'0';
        dp = {  min(dp.f+x,dp.s+x+1),
                min(dp.f+10-x,dp.s+9-x) };
    }
    print(min(dp.f,dp.s+1));

    return 0;
}

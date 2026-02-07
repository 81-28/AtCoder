// https://atcoder.jp/contests/abc444/tasks/abc444_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    int ans=0;
    rep1(i,n) {
        int sm=0;
        for (int d=i; d; d/=10) sm+=d%10;
        ans+=sm==k;
    }
    print(ans);

    return 0;
}

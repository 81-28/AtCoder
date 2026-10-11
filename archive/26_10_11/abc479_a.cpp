// https://atcoder.jp/contests/abc479/tasks/abc479_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int ans=0;
    rep(i,n) {
        int a;
        cin >> a;
        if (i&1) continue;
        ans+=a;
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc478/tasks/abc478_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    int r=m/n;
    int l=m%n;
    rep(i,n) {
        if (i<l) print(r+1);
        else print(r);
    }

    return 0;
}

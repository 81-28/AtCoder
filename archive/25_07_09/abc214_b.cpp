// https://atcoder.jp/contests/abc214/tasks/abc214_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int s,t;
    cin >> s >> t;
    int ans=0;
    rep(a,s+1)rep(b,s+1)rep(c,s+1) {
        if (a+b+c<=s && a*b*c<=t) ++ans;
    }
    print(ans);

    return 0;
}

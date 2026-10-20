// https://atcoder.jp/contests/abc156/tasks/abc156_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using mint=modint1000000007;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


mint c(int n,int k) {
    mint res=1;
    rep(i,k) res*=mint(n-i)/(i+1);
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    cin >> n >> a >> b;
    mint ans=mint(2).pow(n)-1-c(n,a)-c(n,b);
    print(ans.val());

    return 0;
}

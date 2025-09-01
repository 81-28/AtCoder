// https://atcoder.jp/contests/abc414/tasks/abc414_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using mint=modint998244353;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // Σ(b=1~n){n-b+1}
    mint ans=mint(n)*(n+1)/2;
    // Σ(b=1~n){n/b(切り捨て)}
    int l=0,r=n;
    for (int i=1; i*i<=n; ++i) {
        int j=n/i;
        ans-=mint(j)+mint(l)*(r-j);
        l=i,r=j;
    }
    ans-=mint(l)*(r-l);
    print(ans.val());

    return 0;
}

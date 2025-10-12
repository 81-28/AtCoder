// https://atcoder.jp/contests/abc356/tasks/abc356_d

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

    int n,m;
    cin >> n >> m;
    ++n;
    mint ans=0;
    for (int i=1; m; m>>=1,++i) {
        if (!(m%2)) continue;
        int b=(1LL<<i);
        int d=n/b;
        ans+=d*(b/2);
        int r=n%b;
        ans+=max(r-(b/2),0LL);
    }
    print(ans.val());

    return 0;
}

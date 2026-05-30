// https://atcoder.jp/contests/abc460/tasks/abc460_e

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

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        mint ans=0;
        int b=1;
        // 桁数
        for (int d=1; d<19; ++d) {
            if (b>n) break;
            b*=10;
            mint y=min(b-b/10,n+1-b/10);
            int b1=(b%m-1+m)%m;
            int g=gcd(b1,m);
            int step=m/g;
            mint x=n/step;
            ans+=x*y;
        }
        if (n==1e18) {
            mint y=1;
            int b1=((((int)(1e18)%m)*10)%m-1+m)%m;
            int g=gcd(b1,m);
            int step=m/g;
            mint x=n/step;
            ans+=x*y;
        }
        print(ans.val());
    }

    return 0;
}

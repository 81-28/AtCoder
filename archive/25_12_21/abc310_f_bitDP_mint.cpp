// https://atcoder.jp/contests/abc310/tasks/abc310_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // dp[i]:状態i(i[j]:数jが作ることができる)となる確率(10超過は無視)
    int mx=1<<11;
    v<mint> dp(mx,0);
    dp[1]=1;
    while (n--) {
        int a;
        cin >> a;
        v<mint> dpp(mx,0);
        mint inv_a=mint(a).inv();
        rep(i,mx) {
            rep1(j,min(a,10)) {
                int nxt=(i|(i<<j))%mx;
                dpp[nxt]+=dp[i]*inv_a;
            }
            if (a>10) dpp[i]+=dp[i]*inv_a*(a-10);
        }
        dp=dpp;
    }
    mint ans=0;
    for (int i=1<<10; i<mx; ++i) ans+=dp[i];
    print(ans.val());

    return 0;
}

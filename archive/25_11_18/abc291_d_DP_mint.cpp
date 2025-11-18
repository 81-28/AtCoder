// https://atcoder.jp/contests/abc291/tasks/abc291_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    // dp[i]:今の位置で、表裏iの時、それまで全てとなり同士相異なる場合の数
    v<mint> dp(2,1);
    for (int i=1; i<n; ++i) {
        v<mint> ndp(2,0);
        if (a[i]!=a[i-1]) ndp[0]+=dp[0];
        if (a[i]!=b[i-1]) ndp[0]+=dp[1];
        if (b[i]!=a[i-1]) ndp[1]+=dp[0];
        if (b[i]!=b[i-1]) ndp[1]+=dp[1];
        dp=ndp;
    }
    print((dp[0]+dp[1]).val());

    return 0;
}

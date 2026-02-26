// https://atcoder.jp/contests/abc267/tasks/abc267_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // dp[i]:i番目の数として採用した時の最大値
    vi dp(m+1,-INF);
    dp[0]=0;
    rep(i,n) {
        int a;
        cin >> a;
        for(int j=m; j; --j) chmax(dp[j],dp[j-1]+a*j);
    }
    print(dp[m]);

    return 0;
}

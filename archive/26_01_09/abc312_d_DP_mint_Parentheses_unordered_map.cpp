// https://atcoder.jp/contests/abc312/tasks/abc312_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    // dp[i][j]:位置iで深さjであるパターン数
    v<unordered_map<int,mint>> dp(n+1);
    dp[0][0]=1;
    rep(i,n) {
        if (s[i]!=')') {
            for (auto[d,p]:dp[i]) dp[i+1][d+1]+=p;
        }
        if (s[i]!='(') {
            for (auto[d,p]:dp[i]) {
                if (d-1<0) continue;
                dp[i+1][d-1]+=p;
            }
        }
    }
    print(dp[n][0].val());

    return 0;
}

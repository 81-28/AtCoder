// https://atcoder.jp/contests/abc306/tasks/abc306_d

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    // dp[i][j]:状態i(毒か否か01)で前からj個の料理で得られる最大値
    vvll dp(2,vll(n+1,-1e16));
    dp[0][0]=0;
    bool x;
    ll y;
    rep1(i,n) {
        cin >> x >> y;
        if (x) {
            dp[0][i]=dp[0][i-1];
            dp[1][i]=max(dp[0][i-1]+y,dp[1][i-1]);
        } else {
            dp[0][i]=max({dp[0][i-1],dp[0][i-1]+y,dp[1][i-1]+y});
            dp[1][i]=dp[1][i-1];
        }
    }
    print(max(dp[0][n],dp[1][n]));

    return 0;
}

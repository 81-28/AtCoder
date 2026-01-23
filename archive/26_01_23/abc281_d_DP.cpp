// https://atcoder.jp/contests/abc281/tasks/abc281_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,d;
    cin >> n >> k >> d;
    // dp[i][j]:i個選んで、剰余がjである数の最大値
    vvi dp(k+1,vi(d,-1));
    dp[0][0]=0;
    while (n--) {
        int a;
        cin >> a;
        for (int i=k-1; i>=0; --i)rep(j,d) {
            if (dp[i][j]!=-1) {
                chmax(dp[i+1][(j+a)%d],dp[i][j]+a);
            }
        }
    }
    print(dp[k][0]);

    return 0;
}

// https://atcoder.jp/contests/abc271/tasks/abc271_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(n,vi(n));
    cin >> a;
    // dp[i][j][k]:位置ijで、xorがkとなる移動方法の数
    v<v<map<int,int>>> dp(n,v<map<int,int>>(n));
    dp[0][0][a[0][0]]=1;
    rep(i,n)rep(j,n) {
        if (i+j>=n) break;
        if (i) {
            for (auto[num,cnt]:dp[i-1][j]) dp[i][j][num^a[i][j]]+=cnt;
        }
        if (j) {
            for (auto[num,cnt]:dp[i][j-1]) dp[i][j][num^a[i][j]]+=cnt;
        }
    }
    int ans=0;
    dp[n-1][n-1][a[n-1][n-1]]=1;
    for (int i=n-1; i>=0; --i) {
        for (int j=n-1; j>=0; --j) {
            if (i+j==n-1) {
                if (i+1<n) {
                    for (auto[num,cnt]:dp[i+1][j]) ans+=dp[i][j][num]*cnt;
                }
                if (j+1<n) {
                    for (auto[num,cnt]:dp[i][j+1]) ans+=dp[i][j][num]*cnt;
                }
                break;
            }
            if (i+1<n) {
                for (auto[num,cnt]:dp[i+1][j]) dp[i][j][num^a[i][j]]+=cnt;
            }
            if (j+1<n) {
                for (auto[num,cnt]:dp[i][j+1]) dp[i][j][num^a[i][j]]+=cnt;
            }
        }
    }
    print(ans);

    return 0;
}

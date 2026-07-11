// https://atcoder.jp/contests/abc466/tasks/abc466_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,k;
    cin >> n >> k;
    vvi a(n,vi(2));
    cin >> a;
    // dp[i][j]:i枚目まででj回反転した時の最大値
    vvi dp(n+1,vi(k*2+1,-INF));
    dp[0][0]=0;
    rep1(i,n) {
        dp[i][0]=dp[i-1][0]+a[i-1][0];
        rep1(j,k*2) {
            bool b=j&1;
            dp[i][j]=max(dp[i-1][j]+a[i-1][b],dp[i-1][j-1]+a[i-1][b]);
        }
    }
    print(max(dp[n]));

    return 0;
}

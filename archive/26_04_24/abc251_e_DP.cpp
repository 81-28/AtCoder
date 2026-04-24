// https://atcoder.jp/contests/abc251/tasks/abc251_e

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
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int res=0;
    // dp[i][j]:i番目を取り除くかどうかjでの、取り除いた合計値
    vvi dp(n,vi(2,-INF));
    // 0番目を取り除かない場合
    dp[0][0]=0;
    rep1(i,n-1) dp[i]={max(dp[i-1]),dp[i-1][0]+a[i]};
    chmax(res,max(dp[n-1]));
    dp=vvi(n,vi(2,-INF));
    // 0番目を取り除く場合
    dp[0][1]=a[0];
    rep1(i,n-1) dp[i]={max(dp[i-1]),dp[i-1][0]+a[i]};
    chmax(res,dp[n-1][0]);
    print(sum(a)-res);

    return 0;
}

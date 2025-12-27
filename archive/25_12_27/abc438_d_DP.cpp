// https://atcoder.jp/contests/abc438/tasks/abc438_d

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


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b=a,c=a;
    cin >> a >> b >> c;
    // dp[i][j]:iまででj種類の時の合計
    vvi dp(n+1,vi(3,-INF));
    dp[0][0]=a[0];
    rep1(i,n-1) {
        chmax(dp[i][0],dp[i-1][0]+a[i]);
        chmax(dp[i][1],max(dp[i-1][0],dp[i-1][1])+b[i]);
        chmax(dp[i][2],max(dp[i-1][1],dp[i-1][2])+c[i]);
    }
    print(dp[n-1][2]);

    return 0;
}

// https://atcoder.jp/contests/abc261/tasks/abc261_d

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

    int n,m;
    cin >> n >> m;
    vi x(n);
    cin >> x;
    vi a(n+1,0);
    while (m--) {
        int c;
        cin >> c >> a[c];
    }
    // dp[i][j]:i枚目の時点でカウンタがjであるときの最大スコア
    vvi dp(n+1,vi(n+1,-INF));
    dp[0][0]=0;
    // 1つ前の回での最大スコア
    int mx=0;
    rep1(i,n) {
        dp[i][0]=mx;
        rep1(j,n) chmax(mx,dp[i][j]=dp[i-1][j-1]+x[i-1]+a[j]);
    }
    print(mx);

    return 0;
}

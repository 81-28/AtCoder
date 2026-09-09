// https://atcoder.jp/contests/abc175/tasks/abc175_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    cin >> h >> w >> k;
    vvi a(h,vi(w,0));
    while (k--) {
        int r,c,z;
        cin >> r >> c >> z;
        a[--r][--c]=z;
    }
    // dp[i][j][m]:位置ijで、同じ行でm個拾った価値
    v<vvi> dp(h,vvi(w,vi(4,-INF)));
    dp[0][0][0]=0;
    if (a[0][0]) dp[0][0][1]=a[0][0];
    rep(x,h)rep(y,w)rep(m,4) {
        if (x+1<h) {
            chmax(dp[x+1][y][0],dp[x][y][m]);
            if (a[x+1][y]) chmax(dp[x+1][y][1],dp[x][y][m]+a[x+1][y]);
        }
        if (y+1<w) {
            chmax(dp[x][y+1][m],dp[x][y][m]);
            if (a[x][y+1] && m<3) chmax(dp[x][y+1][m+1],dp[x][y][m]+a[x][y+1]);
        }
    }
    print(max(dp[h-1][w-1]));

    return 0;
}

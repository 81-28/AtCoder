// https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1

#include<bits/stdc++.h>
using namespace std;

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
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // dp[i][j]:i個目までの電球で、j回反転した時の最大値
    vvi dp(n,vi(3,1));
    int ans=0;
    rep1(i,n-1) {
        if (a[i]==a[i-1]) {
            chmax(dp[i][1],dp[i-1][0]+1);
            chmax(dp[i][2],dp[i-1][1]+1);
        } else {
            chmax(dp[i][0],dp[i-1][0]+1);
            chmax(dp[i][1],dp[i-1][1]+1);
            chmax(dp[i][2],dp[i-1][2]+1);
        }
        chmax(ans,max(dp[i]));
    }
    print(ans);

    return 0;
}

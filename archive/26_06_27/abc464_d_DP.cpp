// https://atcoder.jp/contests/abc464/tasks/abc464_d

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
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vi x(n),y(n-1);
        cin >> x >> y;
        // dp[i][j]:i日目で、天気が晴れであるjの時の嬉しさの最大値
        vvi dp(n,vi(2,-INF));
        if (s[0]=='S') dp[0]={-x[0],0};
        else dp[0]={0,-x[0]};
        rep1(i,n-1) {
            if (s[i]=='S') {
                chmax(dp[i][0],dp[i-1][0]-x[i]);
                chmax(dp[i][1],dp[i-1][0]+y[i-1]);
                chmax(dp[i][0],dp[i-1][1]-x[i]);
                chmax(dp[i][1],dp[i-1][1]);
            } else {
                chmax(dp[i][0],dp[i-1][0]);
                chmax(dp[i][1],dp[i-1][0]+y[i-1]-x[i]);
                chmax(dp[i][0],dp[i-1][1]);
                chmax(dp[i][1],dp[i-1][1]-x[i]);
            }
        }
        print(max(dp[n-1]));
    }

    return 0;
}

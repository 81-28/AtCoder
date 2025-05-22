// https://atcoder.jp/contests/abc386/tasks/abc386_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    string s;
    cin >> n >> s;
    vll c(n);
    cin >> c;
    // dp[i][j]:i文字目までに状態j,kでの最低スコア
    // j:連続文字があったかどうか,文字iがk(0:1)
    v<vvll> dp(n,vvll(2,vll(2,INT_MAX)));
    if (s[0]-'0') {
        dp[0][0][0]=c[0];
        dp[0][0][1]=0;
    } else {
        dp[0][0][0]=0;
        dp[0][0][1]=c[0];
    }
    for (int i=1; i<n; ++i) {
        if (s[i]-'0') {
            dp[i][0][0] = dp[i-1][0][1]+c[i];
            dp[i][0][1] = dp[i-1][0][0];
            dp[i][1][0] = min(dp[i-1][0][0],dp[i-1][1][1])+c[i];
            dp[i][1][1] = min(dp[i-1][0][1],dp[i-1][1][0]);
        } else {
            dp[i][0][0] = dp[i-1][0][1];
            dp[i][0][1] = dp[i-1][0][0]+c[i];
            dp[i][1][0] = min(dp[i-1][0][0],dp[i-1][1][1]);
            dp[i][1][1] = min(dp[i-1][0][1],dp[i-1][1][0])+c[i];
        }
    }
    print(min(dp[n-1][1]));

    return 0;
}

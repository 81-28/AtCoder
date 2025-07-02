// https://atcoder.jp/contests/abc365/tasks/abc365_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T>constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vi a(n);
    rep(i,n) {
        if (s[i]=='R') a[i]=0;
        if (s[i]=='P') a[i]=1;
        if (s[i]=='S') a[i]=2;
    }
    // dp[i][j]:i回目に出した手がjで、勝つ回数の最大値
    // 出せない場合があるので、初期値(-inf)
    vvi dp(n,vi(3,INT_MIN));
    rep(i,n) {
        if (i) {
            rep(j,3) {
                // // 勝ち
                // if (j==(a[i]+1)%3) {
                //     chmax(dp[i][j],max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+1);
                // }
                // // あいこ
                // if (j==a[i]) {
                //     chmax(dp[i][j],max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]));
                // }
                if (j!=(a[i]+2)%3) {
                    chmax(dp[i][j],max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+(j!=a[i]));
                }
            }
        } else {
            dp[i][a[i]]=0;
            dp[i][(a[i]+1)%3]=1;
        }
    }
    print(max(dp[n-1]));

    return 0;
}

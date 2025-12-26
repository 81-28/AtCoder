// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<char,int> m={
        {'J',0},
        {'O',1},
        {'I',2}
    };
    int mod=10007;
    int n;
    string s;
    cin >> n >> s;
    // dp[i][j]:i日目までで出席状態j(j[k]:m[k]が出席)のパターン数
    vvi dp(n,vi(8,0));
    rep(i,8) {
        if (i&1 && (i>>m[s[0]])&1) dp[0][i]=1;
    }
    rep1(i,n-1) {
        rep(j,8) {
            // 責任者は出席
            if (!((j>>m[s[i]])&1)) continue;
            rep(k,8) {
                // 連続する2日で同じ人が出席
                if (!(j&k)) continue;
                dp[i][j]+=dp[i-1][k];
            }
            dp[i][j]%=mod;
        }
    }
    print(sum(dp[n-1])%mod);

    return 0;
}

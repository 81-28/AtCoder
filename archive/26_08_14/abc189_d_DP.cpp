// https://atcoder.jp/contests/abc189/tasks/abc189_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi dp(2,1);
    while (n--) {
        string s;
        cin >> s;
        dp[s=="OR"]+=dp[0]+dp[1];
        // if (s=="AND") dp={dp[0]*2+dp[1],dp[1]};
        // else dp={dp[0],dp[0]+dp[1]*2};
    }
    print(dp[1]);

    return 0;
}

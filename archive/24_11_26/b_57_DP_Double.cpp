// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ed

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

int calc(const int& n) {
    int sum=0;
    for(int m=n; m>0; m/=10) sum += m%10;
    return n-sum;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,ans;
    cin >> n >> k;
    vvi dp(30,vi(n+1,0));
    rep1(j,n) dp[0][j] = calc(j);
    for(int i=1; i<30; i++) rep1(j,n) dp[i][j] = dp[i-1][dp[i-1][j]];
    rep1(j,n) {
        ans = j;
        for(int i=0; i<30; i++) if(k&(1<<i)) ans = dp[i][ans];
        cout<<ans<<'\n';
    }

    return 0;
}

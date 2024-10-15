#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin >> s >> t;
    int sn = s.size(),tn = t.size();
    vector<vector<int>> dp(sn+1,vector<int>(tn+1,0));
    rep1(i,sn) dp[i][0] = i;
    rep1(j,tn) dp[0][j] = j;
    rep1(i,sn) rep1(j,tn) dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]-(s[i-1] == t[j-1])})+1;
    cout << dp[sn][tn] << endl;
    return 0;
}

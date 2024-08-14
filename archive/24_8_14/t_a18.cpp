// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_r

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}

int main() {
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    cin >> a;

    // dp[i][j] : 最初のi枚まで(のうち何枚か選んで)でjが作れるかどうかの表
    vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
    dp[0][0] = true;
    rep1(i,n) {
        for (int j = 0; j <= s; j++) {
            if (j < a[i-1]) {
                if (dp[i-1][j] == true) dp[i][j] = true;
            } else {
                if (dp[i-1][j] == true || dp[i-1][j-a[i-1]] == true) dp[i][j] = true;
            }
        }
    }
    YesNo(dp[n][s]);

    return 0;
}

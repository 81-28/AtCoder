// https://atcoder.jp/contests/abc343/tasks/abc343_b

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        string ans = "";
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                if (ans != "")
                {
                    ans += " ";
                }
                
                ans += to_string(j+1);
            }
            
        }
        if (ans != "")
        {
            cout << ans << endl;
        }
    }
    

    return 0;
}

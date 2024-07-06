// https://atcoder.jp/contests/abc344/tasks/abc344_d

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
    string t;
    int n;
    cin >> t >> n;
    int a[n];
    string s[n][10];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // i=1
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < a[j]; k++)
            {
                if (s[j][k] == t)
                {
                    cout << i << endl;
                    return 0;
                }
            }
        }
        // i=2
        for (int j = 0; j < n-1; j++)
        {
            for (int k = 0; k < a[j]; k++)
            {
                for (int l = j; l < n; l++)
                {
                    for (int m = 0; m < a[l]; m++)
                    {
                        if (s[j][k] + s[l][m] == t)
                        {
                            cout << i << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        
        cout << -1 << endl;
        return 0;
    }

}

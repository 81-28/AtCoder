// https://atcoder.jp/contests/abc350/tasks/abc350_d

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
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> f(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        f[a][b] = true;
        f[b][a] = true;
    }

    int ans = 0;
    
    for (int l = 0; l < n+1; l++)
    {
    
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                if (!f[i][j] && i!=j)
                {
                    for (int k = 1; k <= n; k++)
                    {
                        if (f[i][k] && f[j][k])
                        {
                            f[i][j] = true;
                            f[j][i] = true;
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
    
    }
    



    
    
    cout << ans << endl;

    return 0;
}

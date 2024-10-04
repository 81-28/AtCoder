// https://atcoder.jp/contests/abc308/tasks/abc308_b

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
    int n,m;
    cin >> n >> m;
    string c[n],d[m];
    int p[m+1];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= m; i++)
    {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i] == d[j])
            {
                ans += p[j+1];
                break;
            }
            if (j == m-1)
            {
                ans += p[0];
            }
        }
    }
    cout << ans << endl;

    return 0;
}

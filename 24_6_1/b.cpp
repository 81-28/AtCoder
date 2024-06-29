// https://atcoder.jp/contests/abc356/tasks/abc356_b

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
    int sum[m];
    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        sum[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int in;
            cin >> in;
            sum[j] += in;

            if (i == n-1)
            {
                if (a[j] > sum[j])
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "Yes" << endl;

    return 0;
}

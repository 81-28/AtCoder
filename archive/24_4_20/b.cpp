// https://atcoder.jp/contests/abc350/tasks/abc350_b

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
    int n,q;
    cin >> n >> q;
    bool te[n];
    for (int i = 0; i < n; i++)
    {
        te[i] = true;
    }

    
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        te[t-1] = !te[t-1];
    }


    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (te[i])
        {
            ans ++;
        }
        
    }

    cout << ans << endl;
    return 0;
}

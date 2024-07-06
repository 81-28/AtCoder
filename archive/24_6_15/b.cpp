// https://atcoder.jp/contests/abc358/tasks/abc358_b

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
    int ans = 0;
    int n,a;
    cin >> n >> a;
    int pans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ans += a;
        int dt = t-pans;
        if (dt >= 0)
        {
            ans += dt;
        }
        cout << ans << endl;
        pans = ans;
    }
    

    return 0;
}

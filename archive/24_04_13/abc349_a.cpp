// https://atcoder.jp/contests/abc349/tasks/abc349_a

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
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a;
        cin >> a;
        ans -= a;
    }
    
    cout << ans << endl;

    return 0;
}

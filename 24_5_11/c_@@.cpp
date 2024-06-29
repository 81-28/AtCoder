// https://atcoder.jp/contests/abc353/tasks/abc353_c

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
    ll ans = 0;
    int n;
    cin >> n;
    ll mul = 0;
    ll a[n];
    for (int i = 0; i < n; i++) {
        ll nowA;
        cin >> nowA;
        a[i] = nowA;
        for (int j = 0; j < i; j++)
        {
            ll sum = a[j]+nowA;
            if (sum >= 100000000)
            {
                mul++;
            }
            ans += sum;
        }
    }
    ans -= 100000000 * mul;
    cout << ans << endl;





    return 0;
}

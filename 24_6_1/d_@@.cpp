// https://atcoder.jp/contests/abc356/tasks/abc356_d

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
    ll MOD = 998244353;
    ll n,m;
    cin >> n >> m;
    // ll div = n / m;
    // ll rem = n % m;
    
    ll tempM = m;
    for (ll i = 0; pow(2,i) <= m; i++)
    {
        ll pow2I = pow(2,i);
        ll mBitI = tempM % 2;
        if (mBitI)
        {
            // ans += (n / (pow2I*2)) + (n % (pow2I*2) - pow2I);
            ans += (n / (pow2I*2))*pow2I + (n % (pow2I*2) - pow2I);
        }
        
        tempM /= 2;
    }
    
    cout << ans % MOD << endl;



    return 0;
}

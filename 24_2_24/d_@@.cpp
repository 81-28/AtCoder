// https://atcoder.jp/contests/abc342/tasks/abc342_d

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
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n-1; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            if(fmod(sqrt(a[i]*a[j]),1.0) == 0.0){
                ans++;
            }
        }
        
    }

    cout << ans << endl;

    return 0;
}

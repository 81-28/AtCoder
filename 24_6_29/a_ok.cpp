// https://atcoder.jp/contests/arc180/tasks/arc180_a

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

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
    ll ans = 1;
    ll mod = 1000000007;

    ll n;
    string s;
    cin >> n >> s;

    ll bar = -1;
    for (ll i = 0; i < n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            ans *= (i-bar+1)/2;
            ans %= mod;
            bar = i;
        }
    }
    ans *= (n-1-bar+1)/2;
    ans %= mod;

    cout << ans << endl;

    return 0;
}

// https://atcoder.jp/contests/abc353/tasks/abc353_d

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

// 桁数を求める関数
// ll len(ll n){
// 	ll digit = 0;
// 	while(n != 0){
// 		n /= 10;
// 		digit++;
// 	}
// 	return digit;
// }
// 桁数を求める関数
// ll len(ll n){
//     return to_string(n).length();
// }


int main() {
    ll ten[11];
    ten[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        ten[i] = ten[i-1] * 10;
    }
    ll MOD = 998244353;
    
    ll ans = 0;
    ll n;
    cin >> n;
    ll sum = 0;
    ll nowA;
    for (ll i = 0; i < n; i++) {
        cin >> nowA;

        ans += (sum * ten[(ll)log10(nowA) + 1]) + (nowA * i);
        ans %= MOD;
        
        sum += nowA;
        sum %= MOD;
    }
    cout << ans << endl;


    return 0;
}

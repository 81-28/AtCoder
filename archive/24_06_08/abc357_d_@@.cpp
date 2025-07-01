// https://atcoder.jp/contests/abc357/tasks/abc357_d

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
    ll MOD = 998244353;
    ll n;
    cin >> n;
    string strN = to_string(n);
    string vs = "";
    for (ll i = 0; i < n; i++)
    {
        vs += strN;
    }
    ll vn = stoll(vs);

    cout << vn % MOD << endl;


    return 0;
}

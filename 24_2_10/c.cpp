// https://atcoder.jp/contests/abc340/tasks/abc340_c

// Ctrl + Shift + B => Build
// Terminal << "./a.out" => Run

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


ll ans = 0;
void func(ll x){
    ans += x;
    if(x/2 >= 2){
        func(x/2);
    }
    if((x+1)/2 >= 2){
        func((x+1)/2);
    }
}

int main() {
    ll n;
    cin >> n;

    if (n>=2)
    {
        func(n);
    }

    cout << ans << endl;

    return 0;
}

// https://atcoder.jp/contests/abc358/tasks/abc358_d

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
    ll n,m;
    cin >> n >> m;
    multiset<ll> multiA;
    multiset<ll> multiB;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        multiA.insert(a);
    }
    for (ll i = 0; i < m; i++)
    {
        ll b;
        cin >> b;
        // if (multiA.find(b) != multiA.end())
        // {
        //     multiA.erase(multiA.find(b));
        // } else {
            multiB.insert(b);
        // }
    }

    for (auto itB = multiB.begin(); itB!=multiB.end();)
    {
        auto itA = multiA.lower_bound(*itB);
        if (itA != multiA.end())
        {
            ans += *itA;
            itA = multiA.erase(itA);
            itB = multiB.erase(itB);
        } else {
            // itB++;
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;



    return 0;
}

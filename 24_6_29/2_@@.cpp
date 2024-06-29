// https://atcoder.jp/contests/arc121/tasks/arc121_b

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
    ll ans = LLONG_MAX;
    ll n;
    cin >> n;
    set<ll> r,g,b,l,m,h;
    for (ll i = 0; i < 2*n; i++)
    {
        ll a;
        char c;
        cin >> a >> c;
        switch (c)
        {
        case 'R':
            r.insert(a);
            break;
        case 'G':
            g.insert(a);
            break;
        case 'B':
            b.insert(a);
            break;
        default:
            break;
        }
    }
    
    ll rNum = r.size();
    ll gNum = g.size();
    ll bNum = b.size();
    if (rNum%2 == 0 && gNum%2 == 0 && bNum%2 == 0)
    {
        cout << 0 << endl;
        return 0;
    } else {
        if (rNum%2 == 0)
        {
            m = r;
            l = g;
            h = b;
        } else if (gNum%2 == 0) {
            m = g;
            l = b;
            h = r;
        } else if (bNum%2 == 0) {
            m = b;
            l = r;
            h = g;
        }

        for (auto lIt = l.begin(); lIt!=l.end(); ++lIt) {
            ll lValue = *lIt;
            auto hIt = h.lower_bound(lValue);
            if (hIt != h.end())
            {
                ll hValue = *hIt;
                if (lValue == hValue)
                {
                    cout << 0 << endl;
                    return 0;
                } else {
                    ans = min(ans,hValue-lValue);
                }
            }
        }
        for (auto hIt = h.begin(); hIt!=h.end(); ++hIt) {
            ll hValue = *hIt;
            auto lIt = l.upper_bound(hValue);
            if (lIt != l.end())
            {
                ll lValue = *lIt;
                ans = min(ans,lValue-hValue);
            }
        }

        // mから2つ取り出して、l,hそれぞれと最小のペアをつくりたい
        // for (auto lIt = l.begin(); lIt!=l.end(); ++lIt) {
        //     ll lValue = *lIt;
        //     for (auto hIt = h.begin(); hIt!=h.end(); ++hIt) {
        //         ll hValue = *hIt;

        //     }
        // }

        cout << ans << endl;
        return 0;
    }

    return 0;
}

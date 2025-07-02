// https://atcoder.jp/contests/abc359/tasks/abc359_e

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

// 最初のTLE提出
// int main() {
//     ll n;
//     cin >> n;
//     vector<ll> h;
//     h.reserve(n);
//     vector<ll> a;
//     a.reserve(n);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> h[i];
//     }

//     for (ll i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             a[0] = h[0]+1;
//         } else {
//             if (h[i] <= h[i-1])
//             {
//                 a[i] = a[i-1] + h[i];
//             } else {
//                 vector<ll> ch(h.begin(), h.begin() + i+1);
//                 ch.reserve(i+1);
//                 auto maxIt = max_element(ch.begin(),ch.end());
//                 ll max = *maxIt;
//                 ll nowH = ch.back();
//                 if (max == nowH)
//                 {
//                     a[i] = (nowH * (i+1)) + 1;
//                 } else {
//                     ll nearHighIndex;
//                     for (ll j = i-1; j >= 0; j--)
//                     {
//                         if (ch[j] > nowH)
//                         {
//                             nearMaxIndex = j;
//                             break;
//                         }
//                     }
//                     a[i] = a[nearMaxIndex] + (nowH * (i-nearMaxIndex));
//                 }
//             }
//         }
        
//         cout << a[i] << endl;
//     }


//     return 0;
// }


int main() {
    ll n;
    cin >> n;
    vector<ll> h;
    h.reserve(n);
    vector<ll> a;
    a.reserve(n);
    set<ll> hSet;
    set<pair<ll,ll>> hIndexSet;
    for (ll i = 0; i < n; i++)
    {
        ll newH;
        cin >> newH;
        h[i] = newH;
        hSet.insert(newH);
        hIndexSet.insert({i,newH});

        if (i == 0)
        {
            a[0] = h[0]+1;
        } else {
            if (h[i] <= h[i-1])
            {
                a[i] = a[i-1] + h[i];
            } else {
                vector<ll> ch(h.begin(), h.begin() + i+1);
                ch.reserve(i+1);
                ll max = *hSet.rbegin();
                ll nowH = ch.back();
                if (max == nowH)
                {
                    a[i] = (nowH * (i+1)) + 1;
                } else {
                    // set<pair<ll,ll>> filteredSet;
                    // copy_if(hIndexSet.begin(),hIndexSet.end(),inserter(filteredSet,filteredSet.end()),[nowH](const pair<ll,ll>& element) {
                    //     return element.second > nowH;
                    // });
                    // ll nearHighIndex = (*filteredSet.rbegin()).first;

                    // auto nearHighIt = hIndexSet.lower_bound({LONG_LONG_MAX, nowH+1});
                    // --nearHighIt;
                    // ll nearHighIndex = nearHighIt->first;

                    ll nearHighIndex = -1;
                    auto nearHighIt = hIndexSet.lower_bound({i, newH + 1});
                    
                    if (nearHighIt != hIndexSet.begin()) {
                        --nearHighIt;
                        nearHighIndex = nearHighIt->first;
                    }

                    a[i] = a[nearHighIndex] + (nowH * (i-nearHighIndex));
                }
            }
        }
        
        cout << a[i] << endl;
    }

    return 0;
}

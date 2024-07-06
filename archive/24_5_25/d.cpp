// https://atcoder.jp/contests/abc355/tasks/abc355_d

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
    int n;
    cin >> n;
    set<P> sec;
    int ans = 0;
    
    // maisuma
    // https://atcoder.jp/contests/abc355/submissions/53856169

    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin >> l >> r;
        // for (int j = 0; j < sec.size(); j++)
        // {
        //     auto it = sec.begin();
        //     advance(it,j);
        
        //     int L = *it.first, R = *it.second;
        //     if (L < l)
        //     {
        //         if (l <= R)
        //         {
        //             ans++;
        //         }
        //     } else if (l < L) {
        //         if (L <= r)
        //         {
        //             ans++;
        //         }
        //     } else {
        //         ans++;
        //     }
        // }
        sec.insert(make_pair(l,r));
    }
    
    // for (auto it = sec.begin(); it != sec.end(); it++) {
    //     auto next_it = next(it);
    //     if (next_it != sec.end()) {
    //         // cout << "現在の要素: " << *it << ", 次の要素: " << *next_it << endl;

    //     }
    // }
    
    cout << ans << endl;



    return 0;
}

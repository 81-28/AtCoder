// https://atcoder.jp/contests/abc355/tasks/abc355_b

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
    int n,m;
    cin >> n >> m;
    set<int> c;
    map<int,bool> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        c.insert(a);
        mp[a] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        c.insert(b);
        mp[b] = false;
    }
    
    for (auto it = c.begin(); it != c.end(); it++) {
        auto next_it = next(it);
        if (next_it != c.end()) {
            if (mp[*it] && mp[*next_it])
            {
                cout << "Yes" << endl;
                return 0;
            }
            
        }
    }
    
    cout << "No" << endl;



    return 0;
}

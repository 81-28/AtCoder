// https://atcoder.jp/contests/abc348/tasks/abc348_c

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
    
    map<int, int> As;
    
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        
        if (As.find(c) == As.end()) {
            As[c] = a;
        } else {
            As[c] = min(As[c], a);
        }
    }
    
    int ans = 0;
    for (const auto& entry : As) {
        ans = max(ans, entry.second);
    }
    
    cout << ans << endl;
    
    return 0;
}

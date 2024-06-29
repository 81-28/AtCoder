// https://atcoder.jp/contests/abc352/tasks/abc352_d

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
    int n, k;
    cin >> n >> k;
    
    vector<int> p(n);
    // 元の数列の要素とそのインデックスをマップする
    map<int, int> idx_map;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        // 要素とインデックスのマッピングを保存
        idx_map[p[i]] = i;
    }

    // ソート後のインデックス
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        idx[i] = idx_map[p[i]];
    }
    
    int ans = n;
    
    for (int i = 0; i <= n - k; ++i) {
        int start = i;
        int end = i + k - 1;
        
        vector<int> sorted_idx(idx.begin() + start, idx.begin() + end + 1);
        sort(sorted_idx.begin(), sorted_idx.end());
        
        int new_diff = sorted_idx[k - 1] - sorted_idx[0];
        ans = min(ans, new_diff);
    }
    
    cout << ans << endl;

    return 0;
}

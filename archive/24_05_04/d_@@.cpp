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
    int n,k;
    cin >> n >> k;
    int ans = n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        int index;
        cin >> index;
        p[index-1] = i;
    }
    
    for (int i = 0; i < n-k+1; i++)
    {
        int MAX = 0;
        int MIN = n;
        for (int j = 0; j < k; j++)
        {
            MAX = max(MAX, p[i+j]);
            MIN = min(MIN, p[i+j]);
        }
        ans = min(ans, MAX-MIN);       
    }
    
    cout << ans << endl;



    return 0;
}

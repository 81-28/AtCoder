// 

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
    int p[n];
    for (int i = 0; i < n; i++)
    {
        int index;
        cin >> index;
        p[index-1] = i;
    }
    
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        s.insert(p[i]);
    }
    int ans = *s.rbegin() - *s.begin();
    
    for (int i = 0; i < n-k+1; i++)
    {
        s.erase(p[i]);
        s.insert(p[i+k]);
        ans = min(ans, *s.rbegin() - *s.begin());
    }
    
    cout << ans << endl;



    return 0;
}

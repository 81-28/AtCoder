// https://atcoder.jp/contests/abc351/tasks/abc351_b

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
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        
    }
    
    for (int i = 0; i < n; i++)
    {
        string b;
        cin >> b;
            
        for (int j = 0; j < n; j++)
        {
            if (b[j] != a[i][j])
            {
                cout << i+1 << ' ' << j+1 << endl;
                return 0; 
            }
        }
        
    }

    return 0;
}

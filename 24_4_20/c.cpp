// https://atcoder.jp/contests/abc350/tasks/abc350_c

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
    int a[n], l[n], r[n];
    int k = 0;

    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (a[j-1] == i)
            {
                l[k] = i;
                r[k] = j;
                a[j-1] = a[i-1];
                a[i-1] = i;
                k++;
                break;
            }
        }
    }
    

    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << l[i] << ' ' << r[i] << endl;
    }

    return 0;
}

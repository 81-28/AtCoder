// https://atcoder.jp/contests/abc357/tasks/abc357_a

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
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        m -= h;
        if (m < 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}

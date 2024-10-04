// https://atcoder.jp/contests/abc354/tasks/abc354_a

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
    int h;
    cin >> h;
    for (int i = 0; i < 30; i++)
    {
        if (h < pow(2,i+1)-1)
        {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}

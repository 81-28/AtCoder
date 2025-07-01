// https://atcoder.jp/contests/abc351/tasks/abc351_a

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
    int a = 0;
    int b = 0;
    for (int i = 0; i < 9; i++)
    {
        int newA;
        cin >> newA;
        a += newA;
    }
    for (int i = 0; i < 8; i++)
    {
        int newB;
        cin >> newB;
        b += newB;
    }
    cout << a-b+1 << endl;
    


    return 0;
}

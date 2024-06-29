// https://atcoder.jp/contests/abc358/tasks/abc358_a

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
    string ansS = "AtCoder";
    string ansT = "Land";
    string s,t;
    cin >> s >> t;
    if (s == ansS && t == ansT)
    {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}

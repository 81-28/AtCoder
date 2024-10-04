// https://atcoder.jp/contests/abc350/tasks/abc350_a

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
    string s;
    // 数字を入力
    cin >> s;
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        num += (s[i+3] - '0') * pow(10,2-i);
    }
    if (num < 1 || num > 349 || num == 316)
    {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}

// https://atcoder.jp/contests/abc360/tasks/abc360_a

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

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
    cin >> s;
    int r = 0,m = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'R')
        {
            r = i;
        } else if (s[i] == 'M')
        {
            m = i;
        }
    }
    
    if (r < m)
    {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    



    return 0;
}

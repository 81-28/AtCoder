// https://atcoder.jp/contests/abc352/tasks/abc352_b

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
    string s,t;
    cin >> s >> t;
    int sN = 0;
    int tN = 0;
    for (int i = 0; i < t.length(); i++)
    {
        if (s[sN] == t[tN])
        {
            cout << tN+1 << endl;
            sN++;
            tN++;
        } else {
            tN++;
        }
        
    }
    

    return 0;
}

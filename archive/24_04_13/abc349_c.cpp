// https://atcoder.jp/contests/abc349/tasks/abc349_c

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
    int nowChar = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (toupper(s[i]) == t[nowChar])
        {
            nowChar++;
        }
        if (nowChar == 3)
        {
            cout << "Yes" << endl;
            return 0;
        } else if (nowChar == 2 && t[2] == 'X'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;

    return 0;
}

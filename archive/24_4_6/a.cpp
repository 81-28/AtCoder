// https://atcoder.jp/contests/abc348/tasks/abc348_a

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
    string s = "";
    for (int i = 0; i < n; i++)
    {
        if (i%3==2)
        {
            s += 'x';
        }else{
            s += 'o';
        }
        
    }
    
    cout << s << endl;

    return 0;
}

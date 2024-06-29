// https://atcoder.jp/contests/abc354/tasks/abc354_b

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
    set<string> setS;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        int c;
        cin >> s >> c;
        setS.insert(s);
        t += c;
    }
    
    auto it = setS.begin();
    advance(it, t%n);
    cout << *it << endl;



    return 0;
}

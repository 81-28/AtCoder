// https://atcoder.jp/contests/abc344/tasks/abc344_b

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
    int n[100];
    int index;
    for (int i = 0; i < 100; i++)
    {
        cin >> n[i];
        if (n[i] == 0)
        {
            index = i;
            break;
        }
        
    }
    for (int i = index; i >= 0; i--)
    {
        cout << n[i] << endl;
    }
    


    return 0;
}

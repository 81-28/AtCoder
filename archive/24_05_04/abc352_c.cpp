// https://atcoder.jp/contests/abc352/tasks/abc352_c

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
    ll a = 0;
    ll b = 0;
    for (int i = 0; i < n; i++)
    {
        ll newA,newB;
        cin >> newA >> newB;
        a += newA;
        if (b < newB-newA)
        {
            b = newB-newA;
        }
        
    }
    
    cout << a+b << endl;


    return 0;
}

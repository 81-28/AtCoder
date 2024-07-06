// https://atcoder.jp/contests/agc019/tasks/agc019_a

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
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    if (q*2 < h)
    {
        h = q*2;
    }
    if (h*2 < s)
    {
        s = h*2;
    }
    if (s*2 < d)
    {
        d = s*2;
    }

    if (n==1)
    {
        cout << s << endl;
    } else {
        if (n%2)
        {
            cout << d * (n-1) / 2 + s<< endl;
        } else {
            cout << d * n / 2 << endl;
        }
        
    }
    
    return 0;
}

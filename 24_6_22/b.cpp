// https://atcoder.jp/contests/abc359/tasks/abc359_b

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
    int ans = 0;
    int n;
    cin >> n;
    int pa = 0;
    int ppa = 0;
    for (int i = 0; i < 2*n; i++)
    {
        int a;
        cin >> a;
        if ((1 < i && ppa == a))
        {
            ans++;
        }

        ppa = pa;
        pa = a;
    }
    
    cout << ans << endl;



    return 0;
}

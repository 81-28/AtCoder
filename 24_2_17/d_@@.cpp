// https://atcoder.jp/contests/abc341/tasks/abc341_d

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
    ll n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    ll p[k];
    ll num = 1;
    for (ll i = 0; i < k; i++)
    {
        while (1)
        {
            if ((num % n == 0 && num % m != 0)||(num % n != 0 && num % m == 0))
            {
                break;
            }
            num++;
        }
        p[i] = num;
        num++;
    }
    

    cout << p[k-1] << endl;




    return 0;
}

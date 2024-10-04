// https://atcoder.jp/contests/abc342/tasks/abc342_b

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
    int n, q;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cin >> q;
    int a[q], b[q];
    for (int i = 0; i < q; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }
    
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == p[j])
            {
                cout << p[j] << endl;
                break;
            }else if(b[i] == p[j]){
                cout << p[j] << endl;
                break;
            }
            
        }
    }


    return 0;
}

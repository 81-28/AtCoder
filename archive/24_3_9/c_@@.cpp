// https://atcoder.jp/contests/abc344/tasks/abc344_c

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
    int n,m,l,q;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    ll b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cin >> l;
    ll c[l];
    for (int i = 0; i < l; i++)
    {
        cin >> c[i];
    }
    cin >> q;
    ll x[q];
    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < q; i++)
    {
        bool ok = false;
        for (int j = 0; j < n; j++)
        {
            if (!ok)
            {
                for (int k = 0; k < m; k++)
                {
                    if (!ok)
                    {
                        for (int o = 0; o < l; o++)
                        {
                            if (a[j]+b[k]+c[o] == x[i] && !ok)
                            {
                                cout << "Yes" << endl;
                                ok = true;
                                break;
                            }
                        }
                    }else{
                        break;
                    }
                }
            }else{
                break;
            }
        }
        if (!ok)
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

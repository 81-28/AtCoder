// https://atcoder.jp/contests/abc355/tasks/abc355_c

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
    int n,t;
    cin >> n >> t;
    bool o[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            o[i][j] = false;
        }
    }
    
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        int I = (a-1)/n, J = (a-1)%n;
        o[I][J] = true;
        // for (int j = 0; j < n; j++)
        // {
        //     for (int k = 0; k < n; k++)
        //     {
        //         if (o[j][k])
        //         {
        //             cout << 'o';
        //         } else {
        //             cout << 'x';
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << endl;


        if (i > n-2) {
            bool rowOk = true;
            for (int j = 0; j < n; j++)
            {
                if (!o[I][j])
                {
                    rowOk = false;
                    break;
                }
            }
            
            bool colOk = true;
            for (int j = 0; j < n; j++)
            {
                if (!o[j][J])
                {
                    colOk = false;
                    break;
                }
            }

            bool xOkl = false;
            if (I==J)
            {
                xOkl = true;
                for (int j = 0; j < n; j++)
                {
                    if (!o[j][j])
                    {
                        xOkl = false;
                        break;
                    }
                }
            }
            bool xOkr = false;
            if (I+J == n-1)
            {
                xOkr = true;
                for (int j = 0; j < n; j++)
                {
                    if (!o[j][n-1-j])
                    {
                        xOkr = false;
                        break;
                    }
                }
            }
            

            if (rowOk || colOk || xOkl || xOkr)
            {
                cout << i+1 << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << endl;

    return 0;
}

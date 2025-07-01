// https://atcoder.jp/contests/abc348/tasks/abc348_c

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
    int ans = 0;
    int a[n],c[n],index[n],data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> c[i];
        index[i] = 0;
        data[i] = 0;

        for (int j = 0; j < i+1; j++)
        {
            if (index[j])
            {
                if (index[j] == c[i])
                {
                    data[j] = (data[j] > a[i]) ? a[i] : data[j];
                    break;
                }
            }else{
                index[j] = c[i];
                data[j] = a[i];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = (data[i] > ans) ? data[i] : ans;
    }
    cout << ans << endl;

    return 0;
}

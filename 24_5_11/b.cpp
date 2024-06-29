// https://atcoder.jp/contests/abc353/tasks/abc353_b

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
    int n,k;
    cin >> n >> k;
    int nowK = k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (nowK < a)
        {
            ans++;
            nowK = k;
        }
        nowK -= a;
        
    }
    ans++;

    cout << ans << endl;



    return 0;
}

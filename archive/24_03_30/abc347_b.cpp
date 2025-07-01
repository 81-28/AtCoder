// https://atcoder.jp/contests/abc347/tasks/abc347_b

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
    string s;
    cin >> s;
    // i:文字数
    for (int i = 1; i <= s.length(); i++)
    {
        string a[s.length()+1-i];
        // j:index
        for (int j = 0; j < s.length()+1-i; j++)
        {
            string now = s.substr(j,i);
            a[j] = now;
            bool ok = true;
            for (int k = 0; k < j; k++)
            {
                if (now == a[k])
                {
                    ok = false;
                }
            }
            if (ok)
            {
                ans++;
            }
        }
    }
    
    cout << ans << endl;


    return 0;
}

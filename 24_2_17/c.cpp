// https://atcoder.jp/contests/abc341/tasks/abc341_c

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
    int h, w, n;
    cin >> h;
    cin >> w;
    cin >> n;
    string t;
    cin >> t;
    string s[h];
    for (int i = 0; i < h; i++)
    {
    cin >> s[i];
    }

    int ans = 0;
    for (int i = 1; i < h-1; i++)
    {
        for (int j = 1; j < w-1; j++)
        {
            bool ok = true;
            int nowI = i;
            int nowJ = j;
            if (s[nowI][nowJ] == '#')
            {
                ok = false;
            }
            for (int k = 0; k < n; k++)
            {
                if (t[k] == 'L')
                {
                    nowJ --;
                }else if (t[k] == 'R')
                {
                    nowJ ++;
                }else if (t[k] == 'U')
                {
                    nowI --;
                }else if (t[k] == 'D')
                {
                    nowI ++;
                }

                if (s[nowI][nowJ] == '#')
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans ++;
            }
            
        }
        
    }
    
    cout << ans << endl;


    return 0;
}

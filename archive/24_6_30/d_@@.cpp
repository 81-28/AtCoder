// https://atcoder.jp/contests/abc360/tasks/abc360_d

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

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
    int n,t;
    string s;
    cin >> n >> t >> s;
    vector<int> antsP;
    vector<int> antsN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        char nows = s[i];
        if (nows == '0')
        {
            antsN.push_back(x);
        } else {
            antsP.push_back(x);
        }
    }

    for (int i = 0; i < antsP.size(); i++)
    {
        for (int j = 0; j < antsN.size(); j++)
        {
            int xp = antsP[i];
            int xn = antsN[j];
            if (xp < xn) {
                if (xp+t >= xn-t)
                {
                    ans++;
                }
            }
        }
    }
    
    
    cout << ans << endl;


    return 0;
}

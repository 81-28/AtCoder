// https://atcoder.jp/contests/abc344/tasks/abc344_a

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
    string s;
    cin >> s;
    string ans = "";
    int stick[2];
    bool first = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '|')
        {
            if (!first)
            {
                stick[0] = i;
                first = true;
            }else{
                stick[1] = i;
            }
            
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (i < stick[0] || stick[1] < i)
        {
            ans += s[i];
        }
    }
    
    cout << ans << endl;


    return 0;
}

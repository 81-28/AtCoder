// https://atcoder.jp/contests/abc357/tasks/abc357_b

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

    int low = 0,up = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            up++;
        } else {
            low++;
        }
    }
    if (up > low)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (islower(s[i]))
            {
                s[i] = toupper(s[i]);
            }
        }
    } else {
        for (int i = 0; i < s.length(); i++)
        {
            if (isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    cout << s << endl;


    return 0;
}

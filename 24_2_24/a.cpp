// https://atcoder.jp/contests/abc342/tasks/abc342_a

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

    int ans1 = 0;
    int ans2 = -1;

    int diff = 0;
    bool isAns1 = false;
    string s;
    cin >> s;
    char c = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            
        }else{
            ans2 = i;
            diff++;
            if(diff >= 2){
                isAns1 = true;
                break;
            }
        }
        
    }
    if(isAns1){
        cout << ans1+1 << endl;
    }else{
        cout << ans2+1 << endl;
    }
    


    return 0;
}

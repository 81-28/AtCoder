// https://atcoder.jp/contests/abc346/tasks/abc346_b

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
    int w,b;
    cin >> w;
    cin >> b;
    int dif = w-b;
    int a = (b)/5;
    int re = 0;
    if ((b)%5 >=1)
    {
        re = 1;
    }
    
    if (dif < 0)
    {
        if (b == 3 && w == 2){
            cout << "Yes" << endl;
            return 0;
        }
    }else{
        if (b == 0)
        {
            if (dif <= 2)
            {
                cout << "Yes" << endl;
                return 0;
            }
            
        }else if (dif <= 2*(a)+re+2)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}

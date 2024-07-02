// 

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
// using P = pair<int,int>;
// using Graph = vector<vector<int>>;
// using mint = modint1000000007;

int main() {
    vector<int> anss;
    int index = 0;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        } else {
            int ans = n;

            anss.push_back(ans);
            anss[index] += ans;
            index++;
        }
    }
    
    rep(i,anss.size()) cout << anss[i] << endl;

    return 0;
}

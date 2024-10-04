// https://atcoder.jp/contests/abc357/tasks/abc357_e

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
    int n;
    cin >> n;
    map<int,int> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> ma[i];
    }
    set<int> setA[n];
    for (int i = 1; i <= n; i++)
    {
        int now = i;
        for (int j = 0; j < n; j++)
        {
            setA[i-1].insert(now);

            now = ma[now];
            // if (now < i)
            // {
            //     for (const auto &element : setA[now-1])
            //     {
            //         setA[i-1].insert(element);
            //     }
            //     break;
            // }
            
            if (setA[i-1].find(now) != setA[i-1].end())
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += setA[i].size();
    }
    
    cout << ans << endl;

    return 0;
}

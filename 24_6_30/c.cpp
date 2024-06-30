// https://atcoder.jp/contests/abc360/tasks/abc360_c

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
    int n;
    cin >> n;
    map<int,vector<int>> wMap;

    vector<int> as;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        as.push_back(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        int a = as[i];
        int w;
        cin >> w;
        wMap[a].push_back(w);
    }

    for (const auto &pair : wMap)
    {
        vector<int> wv = pair.second;
        int sumW = 0;
        set<int> ws;
        for (int i = 0; i < wv.size(); i++)
        {
            int w = wv[i];
            sumW += w;
            ws.insert(w);
        }
        ans += (sumW - *ws.rbegin());
    }
    
    
    cout << ans << endl;



    return 0;
}

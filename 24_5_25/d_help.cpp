// https://atcoder.jp/contests/abc355/tasks/abc355_d

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
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = {l, r};
        events.push_back({l, 1});  // 区間の開始を+1イベントとして記録
        events.push_back({r, -1}); // 区間の終了を-1イベントとして記録
    }

    // イベントを座標、種類の順にソート
    sort(events.begin(), events.end());

    int current_intervals = 0;
    int ans = 0;

    // スイープラインを開始
    for (auto event : events) {
        int coord = event.first;
        int type = event.second;

        if (type == 1) {
            // 区間の開始
            ans += current_intervals;
            current_intervals++;
        } else {
            // 区間の終了
            current_intervals--;
        }
    }

    cout << ans << endl;
    return 0;
}

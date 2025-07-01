// https://atcoder.jp/contests/abc359/tasks/abc359_c

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
    ll ans = 0;
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    ll diffX = abs(tx - sx);
    ll diffY = abs(ty - sy);
    ans = diffY;
    if (diffX > diffY)
    {
        if (((sx+sy)%2 == 0 && sx > tx) || ((sx+sy)%2 == 1 && sx < tx))
        {
            // 目的地に近い側のマス
            ans += ((diffX - diffY)+1)/2;
        } else if (((sx+sy)%2 == 1 && sx > tx) || ((sx+sy)%2 == 0 && sx < tx)) {
            // 目的地に遠い側のマス(無料で一歩近づける)
            ans += ((diffX - diffY))/2;
        } else {
            // sx == tx
        }
    }

    cout << ans << endl;
    



    return 0;
}

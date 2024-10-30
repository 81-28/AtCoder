// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dg
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
using ll = long long;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio();

    int n,x,y;
    cin >> n >> x >> y;
    vector<int> grundy(x+y);
    rep(i,x+y) {
        vector<bool> transit(3,false);
        if (i >= x) transit[grundy[i-x]] = true;
        if (i >= y) transit[grundy[i-y]] = true;
        if (!transit[0]) grundy[i] = 0;
        else if (!transit[1]) grundy[i] = 1;
        else grundy[i] = 2;
    }

    int s = 0;
    ll a;
    rep(_,n) {
        cin >> a;
        s ^= grundy[a%(x+y)];
    }
    cout<<(s?"First\n":"Second\n");

    return 0;
}

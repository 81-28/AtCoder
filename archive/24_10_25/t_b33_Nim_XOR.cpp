// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_df

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio();

    int n,h,w;
    cin >> n >> h >> w;
    int s=0;
    int a;
    rep(i,2*n) {
        cin >> a;
        s ^= a-1;
    }
    cout<<(s==0 ? "Second\n":"First\n");

    return 0;
}
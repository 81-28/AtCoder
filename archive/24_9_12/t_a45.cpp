// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_as

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


int main() {
    fastio();

    int n;
    char c;
    cin >> n >> c;
    int score = 0;
    rep(i,n) {
        char a;
        cin >> a;
        // 操作の前後のスコア(mod3)が変化しないことを利用
        // if (a == 'W') score += 0;
        if (a == 'R') score += 1;
        if (a == 'B') score += 2;
    }
    YesNo((c == 'W' && score%3 == 0) || (c == 'R' && score%3 == 1) || (c == 'B' && score%3 == 2));

    return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aj

#include <bits/stdc++.h>
using namespace std;

#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

int main() {
    int n,k;
    cin >> n >> k;
    int d = k - (n-1)*2;
    if (0 > d) YesNo(false)
    else YesNo(d%2 == 0)

    return 0;
}

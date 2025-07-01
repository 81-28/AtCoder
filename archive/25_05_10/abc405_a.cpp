// https://atcoder.jp/contests/abc405/tasks/abc405_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int r,x;
    cin >> r >> x;
    if (x==1) YesNo(1600<=r && r<3000);
    else YesNo(1200<=r && r<2400);

    return 0;
}

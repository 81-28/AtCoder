// https://atcoder.jp/contests/abc406/tasks/abc406_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (c<a) {
        YesNo(1);
    } else if (a==c) {
        YesNo(d<b);
    } else YesNo(0);

    return 0;
}

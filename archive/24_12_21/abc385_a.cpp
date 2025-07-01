// https://atcoder.jp/contests/abc385/tasks/abc385_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        YesNo(1);
        return 0;
    }
    int s = a+b+c;
    int m = max({a,b,c});
    if (s-m == m) {
        YesNo(1);
        return 0;
    }
    YesNo(0);

    return 0;
}

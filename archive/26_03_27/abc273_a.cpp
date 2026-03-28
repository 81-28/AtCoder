// https://atcoder.jp/contests/abc273/tasks/abc273_a

#include<bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n==0) return 1;
    return n*f(n-1);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    cout<<f(n);

    return 0;
}

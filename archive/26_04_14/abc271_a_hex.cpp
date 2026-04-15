// https://atcoder.jp/contests/abc271/tasks/abc271_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    cout << uppercase << hex << n/16 << n%16;

    return 0;
}

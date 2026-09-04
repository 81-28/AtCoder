// https://atcoder.jp/contests/abc259/tasks/abc259_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,x,t,d;
    cin >> n >> m >> x >> t >> d;
    cout<<(t-d*max(0,x-m));

    return 0;
}
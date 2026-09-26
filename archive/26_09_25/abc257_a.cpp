// https://atcoder.jp/contests/abc257/tasks/abc257_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    cin >> n >> x;
    cout<<(char('A'+(x-1)/n));

    return 0;
}

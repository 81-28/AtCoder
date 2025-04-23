// https://atcoder.jp/contests/abc305/tasks/abc305_a

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int l=n/5*5,r=l+5;
    cout<<((n-l<r-n)?l:r)<<'\n';

    return 0;
}

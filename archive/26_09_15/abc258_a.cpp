// https://atcoder.jp/contests/abc258/tasks/abc258_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h=21,k;
    cin >> k;
    h+=k/60,k%=60;
    printf("%d:%02d",h,k);

    return 0;
}

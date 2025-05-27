// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x;
    cin >> x;
    int c=x/100;
    x-=c*100;
    cout<<(x<=c*5)<<'\n';

    return 0;
}

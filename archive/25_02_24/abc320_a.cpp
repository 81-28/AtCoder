// https://atcoder.jp/contests/abc320/tasks/abc320_a

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    cout<<int(pow(a,b)+pow(b,a))<<'\n';

    return 0;
}

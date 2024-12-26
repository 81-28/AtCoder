// https://atcoder.jp/contests/abc335/tasks/abc335_a

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    s[n-1] = '4';
    cout<<s<<'\n';

    return 0;
}

// https://atcoder.jp/contests/abc329/tasks/abc329_a

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)cout<<(i?" ":"")<<s[i];
    cout<<'\n';

    return 0;
}

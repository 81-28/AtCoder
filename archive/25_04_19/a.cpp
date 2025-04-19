// https://atcoder.jp/contests/abc402/tasks/abc402_a

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    for (char c:s) {
        if (isupper(c))cout<<c;
    }
    cout<<'\n';

    return 0;
}

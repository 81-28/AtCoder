// https://atcoder.jp/contests/abc462/tasks/abc462_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    for (char c:s) {
        if ('0'<=c && c<='9') cout<<c;
    }
    cout<<endl;

    return 0;
}

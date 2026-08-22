// https://atcoder.jp/contests/abc472/tasks/abc472_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    for (char c:s) cout<<(c!='A'?'.':c);
    cout<<endl;

    return 0;
}

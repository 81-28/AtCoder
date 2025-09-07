// https://atcoder.jp/contests/abc422/tasks/abc422_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s[0]-'0',m=s[2]-'0';
    ++m;
    if (m==9) {
        ++n;
        m=1;
    }
    cout<<n<<'-'<<m<<endl;

    return 0;
}

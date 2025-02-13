// https://atcoder.jp/contests/abc323/tasks/abc323_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    for (int i=1; i<16; i+=2) {
        if (s[i]-'0') {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

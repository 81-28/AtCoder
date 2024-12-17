// https://atcoder.jp/contests/abc338/tasks/abc338_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    if (islower(s[0])) {
        YesNo(0);
        return 0;
    }
    for (int i=1; i<n; i++) {
        if (isupper(s[i])) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

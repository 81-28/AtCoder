// https://atcoder.jp/contests/abc337/tasks/abc337_b

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    for (int i=1; i<n; i++) {
        if (s[i]-s[i-1] != 2 && s[i]-s[i-1] != 1 && s[i]-s[i-1] != 0) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

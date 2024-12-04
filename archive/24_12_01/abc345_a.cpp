// https://atcoder.jp/contests/abc345/tasks/abc345_a

#include<bits/stdc++.h>
using namespace std;
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    if (s[0]=='<'&&s[n-1]=='>') {
        for (int i=1; i<n-1; i++) {
            if (s[i]!='=') {
                YesNo(0);
                return 0;
            }
        }
    } else {
        YesNo(0);
        return 0;
    }
    YesNo(1);

    return 0;
}

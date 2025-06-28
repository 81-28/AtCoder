// https://atcoder.jp/contests/abc412/tasks/abc412_b

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    int n=s.size();
    for (int i=1; i<n; ++i) {
        if (isupper(s[i])) {
            int pos=t.find(s[i-1]);
            if (pos==-1) {
                YesNo(0);
                return 0;
            }
        }
    }
    YesNo(1);

    return 0;
}

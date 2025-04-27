// https://atcoder.jp/contests/abc403/tasks/abc403_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string t,u;
    cin >> t >> u;
    int n=t.size(),m=u.size();
    bool ok;
    for (int i=0; i<n+1-m; i++) {
        ok=1;
        rep(j,m) {
            if (t[i+j]!=u[j]&&t[i+j]!='?') {
                ok=0;
                break;
            }
        }
        if (ok) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

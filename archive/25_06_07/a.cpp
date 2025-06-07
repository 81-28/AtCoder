// https://atcoder.jp/contests/abc409/tasks/abc409_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string t,a;
    cin >> n >> t >> a;
    rep(i,n) {
        if (t[i]=='o'&&a[i]=='o') {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

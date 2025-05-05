// https://atcoder.jp/contests/abc303/tasks/abc303_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s,t;
    cin >> n >> s >> t;
    rep(i,n) {
        if (s[i]==t[i] || (s[i]=='l'&&t[i]=='1') || (s[i]=='1'&&t[i]=='l') || (s[i]=='o'&&t[i]=='0') || (s[i]=='0'&&t[i]=='o')) continue;
        YesNo(0);
        return 0;
    }
    YesNo(1);

    return 0;
}
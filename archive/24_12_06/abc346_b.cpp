// https://atcoder.jp/contests/abc346/tasks/abc346_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int w,b;
    cin >> w >> b;
    int q = min(w/7,b/5);
    w -= q*7;
    b -= q*5;
    int n = w+b;
    string s = "wbwbwwbwbwbw";
    s += s;
    rep(i,12) {
        int cw=0,cb=0;
        rep(j,n) {
            if(s[i+j]=='w') cw++;
            else cb++;
        }
        if(cw==w && cb==b) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

// https://atcoder.jp/contests/abc304/tasks/abc304_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    if (n<4) cout<<s;
    else {
        rep(i,n) {
            if (i<3) cout<<s[i];
            else cout<<0;
        }
    }
    cout<<'\n';

    return 0;
}

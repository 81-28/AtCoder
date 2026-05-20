// https://atcoder.jp/contests/abc237/tasks/abc237_d

#include<bits/stdc++.h>
using namespace std;

int n;
string s;
void dfs(int m) {
    if (m==n) {
        cout<<m;
        return;
    }
    if (s[m]=='L') {
        dfs(m+1);
        cout<<' '<<m;
    } else {
        cout<<m<<' ';
        dfs(m+1);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> s;
    dfs(0);
    cout<<endl;

    return 0;
}

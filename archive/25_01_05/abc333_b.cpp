// https://atcoder.jp/contests/abc333/tasks/abc333_b

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    int ds = abs(((s[1]-s[0]+7)%5)-2);
    int dt = abs(((t[1]-t[0]+7)%5)-2);
    YesNo(ds==dt);

    return 0;
}

// https://atcoder.jp/contests/abc294/tasks/abc294_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    rep(i,n) {
        int a;
        cin >> a;
        if (a%2==0) cout<<a<<' ';
    }
    cout<<endl;

    return 0;
}

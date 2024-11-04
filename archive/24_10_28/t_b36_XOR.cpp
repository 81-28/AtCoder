// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_di

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
#define fastio() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
    fastio();

    int n,k;
    string s;
    cin>>n>>k>>s;
    int sum=0;
    rep(i,n)if(s[i]=='1')sum^=1;
    YesNo(sum==k%2);

    return 0;
}

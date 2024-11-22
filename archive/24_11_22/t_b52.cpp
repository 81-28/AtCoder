// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dy

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    string a;
    cin >> n >> x >> a;
    a[x-1]='@';
    for(int i=x-2; i>=0; i--) {
        if(a[i]=='.') a[i]='@';
        else break;
    }
    for(int i=x; i<n; i++) {
        if(a[i]=='.') a[i]='@';
        else break;
    }
    cout<<a<<'\n';

    return 0;
}

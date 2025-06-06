// https://atcoder.jp/contests/abc299/tasks/abc299_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int a=-1,b,c;
    rep(i,n) {
        if (s[i]=='|') {
            if (a==-1) a=i;
            else c=i;
        }
        if (s[i]=='*') b=i;
    }
    puts((a<b&&b<c)?"in":"out");

    return 0;
}

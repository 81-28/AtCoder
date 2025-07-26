// https://atcoder.jp/contests/abc416/tasks/abc416_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    string t=s;
    rep(i,n-1) {
        if (s[i]=='.'&&s[i+1]=='#') t[i]='o';
    }
    if (s[n-1]=='.') t[n-1]='o';
    print(t);

    return 0;
}

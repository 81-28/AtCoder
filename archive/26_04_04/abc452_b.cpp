// https://atcoder.jp/contests/abc452/tasks/abc452_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h,string(w,'.'));
    rep(i,h) s[i][0]=s[i][w-1]='#';
    rep(i,w) s[0][i]=s[h-1][i]='#';
    rep(i,h) print(s[i]);

    return 0;
}

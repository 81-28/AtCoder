// https://atcoder.jp/contests/abc279/tasks/abc279_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(w,string(h,' ')),t=s;
    rep(i,h)rep(j,w) cin >> s[j][i];
    rep(i,h)rep(j,w) cin >> t[j][i];
    sort(all(s)),sort(all(t));
    rep(i,w)rep(j,h) {
        if (s[i][j]!=t[i][j]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

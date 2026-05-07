// https://atcoder.jp/contests/abc268/tasks/abc268_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    int n=s.size(),m=t.size();
    if (n>m) {
        YesNo(0);
        return 0;
    }
    rep(i,n) {
        if (s[i]!=t[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}

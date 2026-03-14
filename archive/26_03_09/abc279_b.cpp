// https://atcoder.jp/contests/abc279/tasks/abc279_b

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
    rep(i,n-m+1) {
        bool ok=1;
        rep(j,m) {
            if(s[i+j]!=t[j]) {
                ok=0;
                break;
            }
        }
        if(ok) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

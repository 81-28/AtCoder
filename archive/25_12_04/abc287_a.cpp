// https://atcoder.jp/contests/abc287/tasks/abc287_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0;
    rep(i,n) {
        string s;
        cin >> s;
        if (s=="For") ++sm;
    }
    YesNo(sm>n/2);

    return 0;
}

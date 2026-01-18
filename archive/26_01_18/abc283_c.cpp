// https://atcoder.jp/contests/abc283/tasks/abc283_c

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
    int ans=n;
    rep(i,n-1) {
        if (s[i]=='0'&&s[i+1]=='0') {
            --ans,++i;
        }
    }
    print(ans);

    return 0;
}

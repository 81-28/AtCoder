// https://atcoder.jp/contests/abc476/tasks/abc476_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s,t;
    cin >> n >> s >> t;
    bool ok=1;
    rep(i,n) {
        if (t[i]=='*') continue;
        if (s[i]!=t[i]) {
            ok=0;
            break;
        }
    }
    YesNo(ok);

    return 0;
}

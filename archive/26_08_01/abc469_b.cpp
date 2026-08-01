// https://atcoder.jp/contests/abc469/tasks/abc469_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    rep(i,n) {
        if (s[i]=='o') continue;
        if (i!=0 && s[i-1]=='o') continue;
        if (i!=n-1 && s[i+1]=='o') continue;
        ++ans;
    }
    print(ans);

    return 0;
}

// https://atcoder.jp/contests/abc243/tasks/abc243_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    string s;
    cin >> n >> x >> s;
    string t="";
    rep(i,n) {
        int l=t.size();
        if (l>0 && t[l-1]!='U' && s[i]=='U') t.pop_back();
        else t.pb(s[i]);
    }
    for (char c:t) {
        if (c=='U') x/=2;
        if (c=='L') x*=2;
        if (c=='R') x=x*2+1;
    }
    print(x);

    return 0;
}

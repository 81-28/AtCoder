// https://atcoder.jp/contests/abc233/tasks/abc233_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    int sm=0;
    rep(i,n) sm+=s[i]-'0';
    string ans="";
    int ca=0;
    for (int i=n-1; i>=0||ca; --i,ca/=10) {
        ca+=sm;
        ans.pb(ca%10+'0');
        if (i>=0) sm-=s[i]-'0';
    }
    for (int i=ans.size()-1; i>=0; --i) cout<<ans[i];
    cout<<endl;

    return 0;
}

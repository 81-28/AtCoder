// https://atcoder.jp/contests/abc446/tasks/abc446_a

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    cout<<"Of"<<char(s[0]-'A'+'a');
    rep1(i,n-1)cout<<s[i];
    cout<<endl;

    return 0;
}

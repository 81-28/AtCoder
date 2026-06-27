// https://atcoder.jp/contests/abc464/tasks/abc464_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    string s;
    cin >> s;
    map<char,int> m;
    for (char c:s) ++m[c];
    print(m['E']>m['W']?"East":"West");

    return 0;
}

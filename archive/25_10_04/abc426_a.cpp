// https://atcoder.jp/contests/abc426/tasks/abc426_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<string,int> m;
    m["Ocelot"]=0;
    m["Serval"]=1;
    m["Lynx"]=2;
    string x,y;
    cin >> x >> y;
    YesNo(m[x]>=m[y]);

    return 0;
}

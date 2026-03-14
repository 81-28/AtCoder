// https://atcoder.jp/contests/abc278/tasks/abc278_c

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    map<pii,bool> m;
    while(q--) {
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1) m[{a,b}]=1;
        if(t==2) m[{a,b}]=0;
        if(t==3) YesNo((m[{a,b}]&&m[{b,a}]));
    }

    return 0;
}
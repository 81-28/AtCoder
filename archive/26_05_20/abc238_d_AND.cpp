// https://atcoder.jp/contests/abc238/tasks/abc238_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a,s;
        cin >> a >> s;
        int r=s-a*2;
        YesNo(r>=0 && !(a&r));
    }

    return 0;
}

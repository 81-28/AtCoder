// https://atcoder.jp/contests/abc266/tasks/abc266_e

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    ld ans=0;
    rep1(i,n) {
        ld res=0;
        rep1(j,6) res+=max(ans,(ld)j)/6;
        ans=res;
    }
    cout<<fixed<<setprecision(16);
    print(ans);

    return 0;
}

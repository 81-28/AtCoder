// https://atcoder.jp/contests/abc460/tasks/abc460_b

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
        int x0,y0,r0,x1,y1,r1;
        cin >> x0 >> y0 >> r0 >> x1 >> y1 >> r1;
        int d2=(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0);
        if (d2>(r0+r1)*(r0+r1)) {
            YesNo(0);
            continue;
        }
        if (d2<(r1-r0)*(r1-r0)) {
            YesNo(0);
            continue;
        }
        YesNo(1);
    }

    return 0;
}

// https://atcoder.jp/contests/abc442/tasks/abc442_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    int vol=0;
    bool b=0;
    while (q--) {
        int a;
        cin >> a;
        if (a==1) ++vol;
        else if (a==2) vol=max(vol-1,0);
        else b^=1;
        YesNo(b&&vol>2);
    }

    return 0;
}

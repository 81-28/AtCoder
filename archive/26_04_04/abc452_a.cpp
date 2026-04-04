// https://atcoder.jp/contests/abc452/tasks/abc452_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m,d;
    cin >> m >> d;
    if (m==1 && d==7) {
        YesNo(1);
        return 0;
    }
    if (m==3 && d==3) {
        YesNo(1);
        return 0;
    }
    if (m==5 && d==5) {
        YesNo(1);
        return 0;
    }
    if (m==7 && d==7) {
        YesNo(1);
        return 0;
    }
    if (m==9 && d==9) {
        YesNo(1);
        return 0;
    }
    YesNo(0);

    return 0;
}

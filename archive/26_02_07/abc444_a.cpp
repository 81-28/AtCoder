// https://atcoder.jp/contests/abc444/tasks/abc444_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int d=n%10;
    n/=10;
    while (n) {
        if (n%10!=d) {
            YesNo(0);
            return 0;
        }
        n/=10;
    }
    YesNo(1);

    return 0;
}

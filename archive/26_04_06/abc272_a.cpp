// https://atcoder.jp/contests/abc272/tasks/abc272_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0;
    while (n--) {
        int a;
        cin >> a;
        sm+=a;
    }
    print(sm);

    return 0;
}

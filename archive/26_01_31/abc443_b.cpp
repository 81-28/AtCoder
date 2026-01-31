// https://atcoder.jp/contests/abc443/tasks/abc443_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    int sm=0;
    for (int i=0; 1; ++i) {
        sm+=n+i;
        if (sm>=k) {
            print(i);
            return 0;
        }
    }

    return 0;
}

// https://atcoder.jp/contests/abc449/tasks/abc449_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,q;
    cin >> h >> w >> q;
    while (q--) {
        int n,m;
        cin >> n >> m;
        if (n==1) {
            print(m*w);
            h-=m;
        }
        if (n==2) {
            print(h*m);
            w-=m;
        }
    }

    return 0;
}

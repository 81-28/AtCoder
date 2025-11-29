// https://atcoder.jp/contests/abc434/tasks/abc434_a

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int w,b;
    cin >> w >> b;
    w*=1000;
    rep1(i,1e6) {
        if (i*b>w) {
            print(i);
            return 0;
        }
    }

    return 0;
}

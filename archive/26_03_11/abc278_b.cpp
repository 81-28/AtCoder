// https://atcoder.jp/contests/abc278/tasks/abc278_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,m;
    cin >> h >> m;
    while(1) {
        int a=h/10,b=h%10;
        int c=m/10,d=m%10;
        if (a*10+c<24 && b*10+d<60) {
            print(h,m);
            return 0;
        }
        ++m;
        if (m==60) {
            m=0;
            ++h;
        }
        if (h==24) h=0;
    }

    return 0;
}
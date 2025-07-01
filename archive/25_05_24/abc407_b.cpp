// https://atcoder.jp/contests/abc407/tasks/abc407_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y;
    cin >> x >> y;
    int a=0;
    double b=36;
    rep1(i,6)rep1(j,6) {
        if (i+j>=x || abs(i-j)>=y) ++a;
    }
    cout<<fixed<<setprecision(20);
    print(a/b);

    return 0;
}

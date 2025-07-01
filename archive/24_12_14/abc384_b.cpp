// https://atcoder.jp/contests/abc384/tasks/abc384_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,r;
    cin >> n >> r;
    int d,a;
    rep(i,n) {
        cin >> d >> a;
        if (d==1 && 1600 <= r && r < 2800) r+=a;
        if (d==2 && 1200 <= r && r < 2400) r+=a;
    }
    print(r);

    return 0;
}

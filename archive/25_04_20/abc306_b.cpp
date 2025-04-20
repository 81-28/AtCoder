// https://atcoder.jp/contests/abc306/tasks/abc306_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ull=unsigned long long;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ull ans=0;
    ull a;
    rep(i,64) {
        cin >> a;
        ans+=a<<i;
    }
    print(ans);

    return 0;
}

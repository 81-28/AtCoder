// https://atcoder.jp/contests/abc332/tasks/abc332_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,s,k;
    cin >> n >> s >> k;
    int p,q;
    int ans=0;
    rep(i,n) {
        cin >> p >> q;
        ans += p*q;
    }
    if (ans < s) ans += k;
    print(ans);

    return 0;
}

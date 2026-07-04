// https://atcoder.jp/contests/abc465/tasks/abc465_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int x,y,l,r,a,b;
    cin >> x >> y >> l >> r >> a >> b;
    int ans=y*(b-a);
    chmax(a,l),chmin(b,r);
    ans+=(x-y)*max(b-a,0);
    print(ans);

    return 0;
}

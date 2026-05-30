// https://atcoder.jp/contests/abc460/tasks/abc460_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    int ans=0;
    while (m!=0) {
        m=n%m;
        ++ans;
    }
    print(ans);

    return 0;
}

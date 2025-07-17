// https://atcoder.jp/contests/abc295/tasks/abc295_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,bool> m;
    int ans=0;
    rep(i,n) {
        int a;
        cin >> a;
        if (m[a]) ++ans;
        m[a]^=1;
    }
    print(ans);

    return 0;
}

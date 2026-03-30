// https://atcoder.jp/contests/abc273/tasks/abc273_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> m;
    rep(i,n) {
        int a;
        cin >> a;
        ++m[a];
    }
    for (auto it=m.rbegin(); it!=m.rend(); ++it) print(it->second);
    rep(i,n-m.size()) print(0);

    return 0;
}

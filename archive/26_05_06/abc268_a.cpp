// https://atcoder.jp/contests/abc268/tasks/abc268_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    set<int> s;
    rep(i,5) {
        int a;
        cin >> a;
        s.insert(a);
    }
    print(s.size());

    return 0;
}

// https://atcoder.jp/contests/abc234/tasks/abc234_d

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    set<int> s;
    rep1(i,n) {
        int p;
        cin >> p;
        s.insert(p);
        if (i>k) s.erase(s.begin());
        if (i>=k) print(*s.begin());
    }

    return 0;
}

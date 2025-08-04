// https://atcoder.jp/contests/abc294/tasks/abc294_d

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    set<int> s,c;
    rep1(i,n) s.insert(i);
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            c.insert(*s.begin());
            s.erase(s.begin());
        }
        if (m==2) {
            int x;
            cin >> x;
            c.erase(c.find(x));
        }
        if (m==3) {
            print(*c.begin());
        }
    }

    return 0;
}

// https://atcoder.jp/contests/abc419/tasks/abc419_c

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    set<int> r,c;
    while (n--) {
        pii p;
        cin >> p;
        r.insert(p.f);
        c.insert(p.s);
    }
    int h=*r.rbegin()-*r.begin();
    int w=*c.rbegin()-*c.begin();
    print((max(h,w)+1)/2);

    return 0;
}

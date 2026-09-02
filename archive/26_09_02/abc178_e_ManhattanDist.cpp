// https://atcoder.jp/contests/abc178/tasks/abc178_e

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/2;
using pii=pair<int,int>;
inline int ManhattanDist(const pii& a,const pii& b){return abs(a.first-b.first)+abs(a.second-b.second);}

#define f first
#define s second

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    pii ur={-INF,-INF};
    pii ul={-INF,INF};
    pii dr={INF,-INF};
    pii dl={INF,INF};
    while (n--) {
        pii p;
        auto&[x,y]=p;
        cin >> x >> y;
        ur = (x+y > ur.f+ur.s) ? p:ur;
        ul = (x-y > ul.f-ul.s) ? p:ul;
        dr = (-x+y > -dr.f+dr.s) ? p:dr;
        dl = (-x-y > -dl.f-dl.s) ? p:dl;
    }
    print(max(ManhattanDist(ur,dl),ManhattanDist(ul,dr)));

    return 0;
}

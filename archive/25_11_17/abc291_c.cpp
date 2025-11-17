// https://atcoder.jp/contests/abc291/tasks/abc291_c

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};

#define f first
#define s second
// pairの加算代入 (+=)
template<typename F,typename S> pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string st;
    cin >> n >> st;
    pii pos={0,0};
    set<pii> trail;
    for (char c:st) {
        trail.insert(pos);
        if (c=='L') pos+=dir[0];
        if (c=='D') pos+=dir[1];
        if (c=='R') pos+=dir[2];
        if (c=='U') pos+=dir[3];
        if (trail.find(pos)!=trail.end()) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}

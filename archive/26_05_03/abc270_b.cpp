// https://atcoder.jp/contests/abc270/tasks/abc270_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y,z;
    cin >> x >> y >> z;
    int r=x>0?1:-1;
    if (y*r>x*r || 0>y*r) print(x*r);
    else if (z*r<y*r) print(abs(z)+(x-z)*r);
    else print(-1);

    return 0;
}

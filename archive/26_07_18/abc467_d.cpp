// https://atcoder.jp/contests/abc467/tasks/abc467_d

#include<bits/stdc++.h>
using namespace std;

using ld=long double;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int t;
    cin >> t;
    while (t--) {
        ld px,py,qx,qy,rx,ry,sx,sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        ld mx=(px+qx)/2;
        ld my=(py+qy)/2;
        ld dx=qx-px;
        ld dy=qy-py;
        ld tmp=dx;
        dx=-dy;
        dy=tmp;

        ld nx=(rx+sx)/2;
        ld ny=(ry+sy)/2;
        ld ex=sx-rx;
        ld ey=sy-ry;
        tmp=ex;
        ex=-ey;
        ey=tmp;

        // 平行じゃないなら、垂直二等分線が交わる
        if (dy*ex != ey*dx) {
            YesNo(1);
            continue;
        }
        // 垂直二等分線が同じなら、条件を満たす
        YesNo(my*dx+(nx-mx)*dy==ny*dx);
    }

    return 0;
}

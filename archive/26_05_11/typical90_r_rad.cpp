// https://atcoder.jp/contests/typical90/tasks/typical90_r

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
const ld PI=acos(-1);

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t,l,x,y,q;
    cin >> t >> l >> x >> y >> q;
    cout << fixed << setprecision(16);
    while (q--) {
        int e;
        cin >> e;
        // E869120君の観覧車の角度と座標
        ld theta=PI*2*e/t;
        ld ey=l/2.0 * -sin(theta);
        ld ez=l/2.0 * (1-cos(theta));
        // E869120君から高橋直大像を見たときの位置ベクトル
        ld dx=x, dy=y-ey;
        // 制約よりdx>0なので、0除算は行われない
        // 俯角(ラジアン)
        ld rad=atan(ez/sqrt(dx*dx+dy*dy));
        // ラジアンを角度に変換
        print(rad*180/PI);
    }

    return 0;
}

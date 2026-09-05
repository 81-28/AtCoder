// https://atcoder.jp/contests/arc225/tasks/arc225_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cmb=0;
        bool ok=1;
        while (n--) {
            int a;
            cin >> a;
            if (a) ++cmb;
            else {
                if (cmb!=2&&cmb) ok=0;
                cmb=0;
            }
        }
        if (cmb!=2&&cmb) ok=0;
        // 負けるのは、2の塊のみの状態の時(全0も含む)
        // 最初にその負け確じゃない場合、相手を負け確にできる
        print(ok?"Bob":"Alice");
    }

    return 0;
}

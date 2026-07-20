// https://atcoder.jp/contests/arc225/tasks/arc225_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,int> m;
        int cmb=0;
        while (n--) {
            int a;
            cin >> a;
            if (a) ++cmb;
            else {
                if (cmb) ++m[cmb];
                cmb=0;
            }
        }
        if (cmb) ++m[cmb];
        // 負けるのは、2の塊のみの状態の時(全0も含む)
        // 最初にその負け確じゃない場合、相手を負け確にできる
        print((m.size()==1 && m[2]>0) || m.size()==0 ?"Bob":"Alice");
    }

    return 0;
}

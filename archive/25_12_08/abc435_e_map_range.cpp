// https://atcoder.jp/contests/abc435/tasks/abc435_e

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    int ans=n;
    // 0:左端,1:右端
    map<int,bool> mp;
    // 黒の範囲[l,r)とする
    while (q--) {
        int l,r;
        cin >> l >> r;
        --l;
        // - 境目が白い所にある場合、何もしない
        // - 境目が黒い所にある場合(と同じ側の端と重なっている場合)と反対側の端と重なっている場合、
        //   範囲を拡張して、打消しで数合わせを行う
        // 元々黒かった部分を除外した範囲を減算
        int sub=0;
        auto itl=mp.upper_bound(l);
        if (itl!=mp.begin()) {
            --itl;
            if (!itl->second) {
                l=itl->first;
                sub+=l;
            } else if (itl->first==l) {
                --itl;
                l=itl->first;
                sub+=l;
            }
        }
        mp[l]=0;
        auto itr=mp.lower_bound(r);
        if (itr!=mp.end()) {
            if (itr->second) {
                r=itr->first;
                sub-=r;
            } else if (itr->first==r) {
                ++itr;
                r=itr->first;
                sub-=r;
            }
        }
        mp[r]=1;
        sub+=r-l;
        itl=mp.upper_bound(l);
        itr=mp.lower_bound(r);
        for (auto it=itl; it!=itr; it=mp.erase(it)) {
            if (it->second) sub-=it->first;
            else sub+=it->first;
        }
        ans-=sub;
        print(ans);
    }

    return 0;
}

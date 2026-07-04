// https://atcoder.jp/contests/abc465/tasks/abc465_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int t;
    cin >> t;
    while (t--) {
        int x,y,k;
        cin >> x >> y >> k;
        // k進数
        deque<int> xk,yk;
        for (int i=x; i>0; i/=k) xk.pb(i%k);
        for (int i=y; i>0; i/=k) yk.pb(i%k);
        int xl=xk.size(),yl=yk.size();
        int l=max(xl,yl);
        for (int i=xl; i<l; ++i) xk.push_front(-1);
        for (int i=yl; i<l; ++i) yk.push_front(-1);
        bool ok=1;
        int ans=0;
        // 1桁ずつ、下から削ったり、加えたりの操作が可能
        // 上位が一致しているなら、その分操作する必要が無い
        for (int i=l-1; i>=0; --i) {
            int xn=xk.back();
            xk.pop_back();
            int yn=yk.back();
            yk.pop_back();
            if (ok && xn==yn) continue;
            ok=0;
            if (xn!=-1) ++ans;
            if (yn!=-1) ++ans;
        }
        print(ans);
    }

    return 0;
}

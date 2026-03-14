// https://atcoder.jp/contests/abc449/tasks/abc449_d

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,r,d,u;
    cin >> l >> r >> d >> u;
    int ans=0;
    for (int x=l; x<=r; ++x) {
        int ab=abs(x);
        int add=0;
        if (d>=0) {
            if (ab%2) {
                if (u>=ab) add+=(u-ab+1)/2;
                if (d-1>=ab) add-=(d-1-ab+1)/2;
            } else {
                if (u>=ab) add+=(u-ab)/2;
                add+=min(u,ab)+1;
                if (d-1>=ab) add-=(d-1-ab)/2;
                add-=min(d-1,ab)+1;
            }
        } else if (u<0) {
            if (ab%2) {
                if (-u-1>=ab) add-=(-u-1-ab+1)/2;
                if (-d>=ab) add+=(-d-ab+1)/2;
            } else {
                if (-u-1>=ab) add-=(-u-1-ab)/2;
                add-=min(-u-1,ab);
                if (-d>=ab) add+=(-d-ab)/2;
                add+=min(-d,ab);
            }
        } else {
            if (ab%2) {
                if (u>=ab) add+=(u-ab+1)/2;
                if (-d>=ab) add+=(-d-ab+1)/2;
            } else {
                if (u>=ab) add+=(u-ab)/2;
                add+=min(u,ab)+1;
                if (-d>=ab) add+=(-d-ab)/2;
                add+=min(-d,ab);
            }
        }
        ans+=add;
    }
    print(ans);

    return 0;
}

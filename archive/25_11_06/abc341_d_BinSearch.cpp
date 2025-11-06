// https://atcoder.jp/contests/abc341/tasks/abc341_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    int n,m,k;
    cin >> n >> m >> k;
    int lc=lcm(n,m);
    // [l,r]
    int l=1,r=LLONG_MAX>>1;
    while (l<r) {
        int mid=(l+r)/2;
        int cnt=mid/n + mid/m - mid/lc*2;
        // cnt==kだからと言って、midが答えとは限らない
        // 答えは、cnt==kとなる最小のmid
        if (cnt<k) l=mid+1;
        else r=mid;
    }
    print(l);

    return 0;
}

// https://atcoder.jp/contests/abc269/tasks/abc269_e

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int l=1,r=n+1;
    while (l+1<r) {
        int m=(l+r)/2;
        print('?',m,r-1,1,n);
        int cnt;
        cin >> cnt;
        if (cnt==r-m) r=m;
        else l=m;
    }
    int x=l;
    l=1,r=n+1;
    while (l+1<r) {
        int m=(l+r)/2;
        print('?',1,n,m,r-1);
        int cnt;
        cin >> cnt;
        if (cnt==r-m) r=m;
        else l=m;
    }
    int y=l;
    print('!',x,y);

    return 0;
}

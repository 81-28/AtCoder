// https://atcoder.jp/contests/abc462/tasks/abc462_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        x=abs(x),y=abs(y);
        int m=min(x,y);
        int ans=min(a,b)*m*2;
        if (x==y) {
            print(ans);
            continue;
        }
        int i=m,j=m;
        if (a<b) {
            if (j==y) {
                ans+=(x-i+1)/2*a;
                ans+=(x-i)/2*min(a*3,b);
            } else {
                ans+=(y-j)/2*a;
                ans+=(y-j+1)/2*min(a*3,b);
            }
        } else {
            if (j==y) {
                ans+=(x-i)/2*b;
                ans+=(x-i+1)/2*min(b*3,a);
            } else {
                ans+=(y-j+1)/2*b;
                ans+=(y-j)/2*min(b*3,a);
            }
        }
        print(ans);
    }

    return 0;
}

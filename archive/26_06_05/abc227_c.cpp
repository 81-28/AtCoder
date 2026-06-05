// https://atcoder.jp/contests/abc227/tasks/abc227_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int ans=0;
    for (int a=1; a*a*a<=n; ++a) {
        for (int b=a; b*b<=n/a; ++b) {
            ans+=n/a/b-(b-1);
        }
    }
    print(ans);

    return 0;
}

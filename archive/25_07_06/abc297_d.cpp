// https://atcoder.jp/contests/abc297/tasks/abc297_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    int ans=0;
    while (a!=b) {
        if (a%b==0 || b%a==0) {
            int c=min(a,b);
            ans+=(a+b)/c-2;
            a=b=c;
        } else if (a>b) {
            ans+=a/b;
            a%=b;
        } else {
            ans+=b/a;
            b%=a;
        }
    }
    print(ans);

    return 0;
}

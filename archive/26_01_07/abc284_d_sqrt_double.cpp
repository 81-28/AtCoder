// https://atcoder.jp/contests/abc284/tasks/abc284_d

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
        int n;
        cin >> n;
        int p=2;
        while (1) {
            if (n%p==0) break;
            ++p;
        }
        if ((n/p)%p==0) print(p,n/p/p);
        else print((int)sqrt(n/p),p);
    }

    return 0;
}

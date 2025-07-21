// https://atcoder.jp/contests/abc298/tasks/abc298_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using mint=modint998244353;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    mint ans=1;
    queue<mint> qu;
    qu.push(1);
    while (q--) {
        int n;
        cin >> n;
        if (n==1) {
            int x;
            cin >> x;
            ans=ans*10+x;
            qu.push(x);
        }
        if (n==2) {
            mint m=qu.front();
            qu.pop();
            ans-=m*mint(10).pow(qu.size());
        }
        if (n==3) print(ans.val());
    }

    return 0;
}

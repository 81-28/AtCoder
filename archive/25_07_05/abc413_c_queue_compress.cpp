// https://atcoder.jp/contests/abc413/tasks/abc413_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;
#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    // {数,個数}
    queue<pii> qu;
    while (q--) {
        int n;
        cin >> n;
        if (n==1) {
            int c,x;
            cin >> c >> x;
            qu.push({x,c});
        }
        if (n==2) {
            int k;
            cin >> k;
            int ans=0;
            while (1) {
                auto&[x,c]=qu.front();
                if (c>=k) {
                    ans+=x*k;
                    c-=k;
                    if (c==0) qu.pop();
                    break;
                } else {
                    ans+=x*c;
                    k-=c;
                    qu.pop();
                }
            }
            print(ans);
        }
    }

    return 0;
}

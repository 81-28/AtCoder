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
    deque<pii> qu;
    while (q--) {
        int n;
        cin >> n;
        if (n==1) {
            int c,x;
            cin >> c >> x;
            qu.push_back({x,c});
        }
        if (n==2) {
            int k;
            cin >> k;
            int ans=0;
            while (1) {
                pii p=qu.front();
                if (p.s>=k) {
                    ans+=p.f*k;
                    p.s-=k;
                    qu.pop_front();
                    if (p.s!=0) {
                        qu.push_front(p);
                    }
                    break;
                } else {
                    ans+=p.f*p.s;
                    k-=p.s;
                    qu.pop_front();
                }
            }
            print(ans);
        }
    }

    return 0;
}

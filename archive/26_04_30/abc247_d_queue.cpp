// https://atcoder.jp/contests/abc247/tasks/abc247_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;

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
            int x,c;
            cin >> x >> c;
            qu.push({x,c});
        } else {
            int c;
            cin >> c;
            int res=0;
            while (c>0) {
                auto&[num,cnt]=qu.front();
                if (cnt>c) {
                    res+=num*c;
                    cnt-=c;
                    c=0;
                } else {
                    res+=num*cnt;
                    c-=cnt;
                    qu.pop();
                }
            }
            print(res);
        }
    }

    return 0;
}

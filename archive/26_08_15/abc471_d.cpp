// https://atcoder.jp/contests/abc471/tasks/abc471_d

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q,x;
    cin >> q >> x;
    set<pii> s;
    while (q--) {
        int m,t,w;
        cin >> m >> t;
        if (m&1) {
            cin >> w;
            s.insert({w-t,t});
        } else {
            if (s.empty()) {
                print(-1);
                continue;
            }
            auto it=s.end();
            --it;
            auto[d,tt]=*it;
            print(min(x,d+t));
            s.erase(it);
        }
    }

    return 0;
}

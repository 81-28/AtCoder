// https://atcoder.jp/contests/abc257/tasks/abc257_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<tuple<int,int,int>> t(n);
    for (auto&[x,y,p]:t) cin >> x >> y >> p;
    // (l,r]
    int l=0,r=1e10;
    while (l+1<r) {
        int m=(l+r)/2;
        bool ok=0;
        rep(i,n) {
            vi b(n,0);
            queue<int> q;
            b[i]=1;
            q.push(i);
            while (!q.empty()) {
                int pos=q.front();
                q.pop();
                auto[x,y,p]=t[pos];
                rep(nxt,n) {
                    if (b[nxt]) continue;
                    auto[xx,yy,pp]=t[nxt];
                    if (p*m>=abs(xx-x)+abs(yy-y)) {
                        b[nxt]=1;
                        q.push(nxt);
                    }
                }
            }
            if (sum(b)==n) {
                ok=1;
                break;
            }
        }
        if (ok) r=m;
        else l=m;
    }
    print(r);

    return 0;
}

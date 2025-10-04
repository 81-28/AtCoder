// https://atcoder.jp/contests/abc426/tasks/abc426_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // {バージョン,個数}
    priority_queue<pii,v<pii>,greater<>> pq;
    rep1(i,n) pq.push({i,1});
    while (q--) {
        int x,y;
        cin >> x >> y;
        int ans=0;
        while (!pq.empty()) {
            auto[ver,num]=pq.top();
            if (ver>x) break;
            pq.pop();
            ans+=num;
        }
        print(ans);
        if (ans) pq.push({y,ans});
    }

    return 0;
}

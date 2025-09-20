// https://atcoder.jp/contests/abc424/tasks/abc424_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(n);
    vi b(n,0);
    queue<int> q;
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        if (x==0) {
            q.push(i);
        } else {
            g[x-1].pb(i);
            g[y-1].pb(i);
        }
    }
    while (!q.empty()) {
        int val=q.front();
        q.pop();
        if (b[val]) continue;
        b[val]=1;
        for (int nxt:g[val]) {
            if (!b[nxt]) q.push(nxt);
        }
    }
    print(sum(b));

    return 0;
}

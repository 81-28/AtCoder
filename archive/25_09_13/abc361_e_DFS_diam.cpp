// https://atcoder.jp/contests/abc361/tasks/abc361_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// m[i][j]:町iとjを結ぶ道路の長さ
v<map<int,int>> m;
// 訪問済みか
v<bool> b;
// {頂点nから最も遠い頂点,距離}
pii dfs(const int& n) {
    b[n]=1;
    int e=n,mx=0;
    for (auto[nxt,c]:m[n]) {
        if (b[nxt]) continue;
        pii p=dfs(nxt);
        if (chmax(mx,p.s+m[n][nxt])) e=p.f;
    }
    return {e,mx};
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    m=v<map<int,int>>(n+1);
    int sm=0;
    rep(i,n-1) {
        int a,b,c;
        cin >> a >> b >> c;
        m[a][b]=c;
        m[b][a]=c;
        sm+=c;
    }
    b=v<bool>(n+1,0);
    int e=dfs(1).f;
    b=v<bool>(n+1,0);
    print((sm<<1)-dfs(e).s);

    return 0;
}

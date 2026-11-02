// https://atcoder.jp/contests/abc318/tasks/abc318_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n;
vvi d;
vb b;
int dfs() {
    int x=-1;
    rep(i,n) {
        if (b[i]) continue;
        x=i;
        break;
    }
    if (x==-1) return 0;
    int res=0;
    b[x]=1;
    rep(y,n) {
        if (b[y]) continue;
        b[y]=1;
        chmax(res,dfs()+d[x][y]);
        b[y]=0;
    }
    b[x]=0;
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    d=vvi(n+1,vi(n+1,0));
    rep(i,n-1)for(int j=i+1; j<n; ++j) cin >> d[i][j];
    if (n&1) ++n;
    b=vb(n,0);
    print(dfs());

    return 0;
}

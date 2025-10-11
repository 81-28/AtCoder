// https://atcoder.jp/contests/abc427/tasks/abc427_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// 状態iで頂点j-1が頂点0と違う色か
bool c(const int& i,const int& j) {
    if (!j) return 0;
    return (i>>(j-1))%2;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<v<bool>> mp(n,v<bool>(n,0));
    rep(i,m ) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        mp[a][b]=1;
        mp[b][a]=1;
    }
    int mx=1<<(n-1);
    int ans=INT_MAX;
    rep(i,mx) {
        int res=0;
        for (int j=0; j<n-1; ++j) for (int k=j+1; k<n; ++k) {
            if (mp[j][k] && (c(i,j)==c(i,k))) ++res;
        }
        chmin(ans,res);
    }
    print(ans);

    return 0;
}

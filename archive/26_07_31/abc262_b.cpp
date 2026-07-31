// https://atcoder.jp/contests/abc262/tasks/abc262_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvb b(n,vb(n,0));
    while (m--) {
        int u,v;
        cin >> u >> v;
        b[--u][--v]=1;
    }
    int ans=0;
    for (int i=0; i<n-2; ++i)
        for (int j=i+1; j<n-1; ++j)
            for (int k=j+1; k<n; ++k)
                ans+=b[i][j]&&b[j][k]&&b[i][k];
    print(ans);

    return 0;
}

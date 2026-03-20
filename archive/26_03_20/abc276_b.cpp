// https://atcoder.jp/contests/abc276/tasks/abc276_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<set<int>> g(n+1);
    while (m--) {
        int a,b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    rep1(i,n) {
        cout<<g[i].size();
        for (int val:g[i])  cout<<' '<<val;
        cout<<endl;
    }

    return 0;
}

// https://atcoder.jp/contests/abc417/tasks/abc417_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    multiset<int> s;
    rep(i,n) {
        int a;
        cin >> a;
        s.insert(a);
    }
    rep(i,m) {
        int b;
        cin >> b;
        auto it=s.find(b);
        if (it!=s.end()) s.erase(it);
    }
    for (int val:s) cout<<val<<' ';
    cout<<endl;

    return 0;
}

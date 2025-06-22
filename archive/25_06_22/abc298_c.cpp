// https://atcoder.jp/contests/abc298/tasks/abc298_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<multiset<int>> b(n+1);
    map<int,set<int>> idx;
    while (q--) {
        int m,i,j;
        cin >> m >> i;
        if (m==1) {
            cin >> j;
            b[j].insert(i);
            idx[i].insert(j);
        }
        if (m==2) {
            for (int val:b[i]) cout<<val<<' ';
            cout<<endl;
        }
        if (m==3) {
            for (int val:idx[i]) cout<<val<<' ';
            cout<<endl;
        }
    }

    return 0;
}

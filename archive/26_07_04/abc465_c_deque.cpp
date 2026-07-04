// https://atcoder.jp/contests/abc465/tasks/abc465_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    string s;
    cin >> n >> s;
    bool b=0;
    deque<int> q;
    rep(i,n) {
        if (!b) q.pb(i+1);
        else q.push_front(i+1);
        if (s[i]=='o') b^=1;
    }
    if (!b) {
        while (!q.empty()) {
            int a=q.front();
            q.pop_front();
            cout<<a<<' ';
        }
    } else {
        while (!q.empty()) {
            int a=q.back();
            q.pop_back();
            cout<<a<<' ';
        }
    }
    cout<<endl;

    return 0;
}

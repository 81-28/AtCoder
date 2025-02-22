// https://atcoder.jp/contests/abc394/tasks/abc394_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pair<int,string>> p(n);
    string s;
    rep(i,n) {
        cin >> s;
        p[i].second = s;
        p[i].first = s.size();
    }
    sort(all(p));
    rep(i,n) cout << p[i].second;
    cout<<'\n';

    return 0;
}

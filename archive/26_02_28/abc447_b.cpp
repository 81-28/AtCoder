// https://atcoder.jp/contests/abc447/tasks/abc447_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    vi cnt(26,0);
    for (char c:s) ++cnt[c-'a'];
    int mx=0;
    for (int val:cnt) chmax(mx,val);
    for (char c:s) {
        if (cnt[c-'a']==mx) continue;
        cout<<c;
    }
    cout<<endl;

    return 0;
}

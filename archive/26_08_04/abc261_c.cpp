// https://atcoder.jp/contests/abc261/tasks/abc261_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    cin >> s;
    unordered_map<string,int> m;
    for (string t:s) {
        cout<<t;
        if (m[t]) cout<<'('<<m[t]<<')';
        cout<<endl;
        ++m[t];
    }

    return 0;
}

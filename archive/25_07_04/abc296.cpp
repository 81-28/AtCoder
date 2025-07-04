// https://atcoder.jp/contests/abc296/tasks/abc296_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<string> s(8);
    cin >> s;
    rep(i,8)rep(j,8) {
        if (s[i][j]=='*') {
            cout<<char('a'+j)<<char('1'+(7-i))<<endl;
            return 0;
        }
    }

    return 0;
}

// https://atcoder.jp/contests/abc445/tasks/abc445_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    cin >> s;
    int l=0;
    rep(i,n) chmax(l,(int)s[i].size());
    rep(i,n) {
        int d=l-s[i].size();
        d/=2;
        rep(j,d)cout<<'.';
        cout<<s[i];
        rep(j,d)cout<<'.';
        cout<<endl;
    }

    return 0;
}

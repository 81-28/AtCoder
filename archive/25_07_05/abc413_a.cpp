// https://atcoder.jp/contests/abc413/tasks/abc413_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

#define YesNo(x) puts(x?"Yes":"No")

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    YesNo(sum(a)<=m);

    return 0;
}

// https://atcoder.jp/contests/abc398/tasks/abc398_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rall(v) v.rbegin(),v.rend()
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(7);
    cin >> a;
    vi c(14,0);
    rep(i,7) c[a[i]]++;
    sort(rall(c));
    YesNo(c[0]>2 && c[1]>1);

    return 0;
}

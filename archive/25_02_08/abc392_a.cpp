// https://atcoder.jp/contests/abc392/tasks/abc392_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(3);
    cin >> a;
    bool ok=0;
    if (a[0] == a[1]*a[2]) ok=1;
    if (a[1] == a[2]*a[0]) ok=1;
    if (a[2] == a[0]*a[1]) ok=1;
    YesNo(ok);

    return 0;
}

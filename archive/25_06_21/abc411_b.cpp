// https://atcoder.jp/contests/abc411/tasks/abc411_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi d(n-1);
    cin >> d;
    vi s(n,0);
    rep1(i,n-1) s[i]=s[i-1]+d[i-1];
    rep(i,n-1) {
        for (int j=i+1; j<n; ++j) cout<<s[j]-s[i]<<' ';
        cout<<endl;
    }

    return 0;
}

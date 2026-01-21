// https://atcoder.jp/contests/abc282/tasks/abc282_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n,0);
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,m) a[i]|=((s[j]=='o')<<j);
    }
    int ans=0;
    int all=(1<<m)-1;
    rep(i,n-1)for(int j=i+1; j<n; ++j) {
        ans+=(a[i]|a[j])==all;
    }
    print(ans);

    return 0;
}

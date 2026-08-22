// https://atcoder.jp/contests/abc472/tasks/abc472_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vi a(n);
    cin >> a;
    int sm=0;
    vb res(n);
    rep(i,n) {
        if (i-m>=0 && res[i-m]) sm-=a[i-m];
        res[i]=sm+a[i]<=k;
        YesNo(res[i]);
        if (res[i]) sm+=a[i];
    }

    return 0;
}

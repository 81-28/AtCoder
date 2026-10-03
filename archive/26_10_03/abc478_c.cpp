// https://atcoder.jp/contests/abc478/tasks/abc478_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    vi b=a;
    sort(all(b));
    int l=0,r=n;
    rep(i,n) {
        if (a[i]!=b[i]) break;
        l=i+1;
    }
    for (int i=n-1; i>=0; --i) {
        if (a[i]!=b[i]) break;
        r=i;
    }
    YesNo(max(0,r-l)<=k);

    return 0;
}

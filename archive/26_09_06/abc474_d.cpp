// https://atcoder.jp/contests/abc474/tasks/abc474_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b(n);
    cin >> a >> b;
    vi ans(n);
    bool ok=0;
    rep(i,n) {
        int d=a[i]-b[i];
        if (d>0) {
            ok=1;
            ans[i]=1e18;
        } else {
            ans[i]=1;
        }
    }
    if (!ok) {
        YesNo(0);
        return 0;
    }
    YesNo(1);
    print(ans);

    return 0;
}

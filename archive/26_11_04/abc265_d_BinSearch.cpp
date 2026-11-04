// https://atcoder.jp/contests/abc265/tasks/abc265_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,p,q,r;
    cin >> n >> p >> q >> r;
    vi a(n);
    cin >> a;
    vi s(n+1,0);
    rep(i,n) s[i+1]=s[i]+a[i];
    rep(x,n) {
        if (!binary_search(all(s),s[x]+p)) continue;
        if (!binary_search(all(s),s[x]+p+q)) continue;
        if (!binary_search(all(s),s[x]+p+q+r)) continue;
        YesNo(1);
        return 0;
    }
    YesNo(0);

    return 0;
}

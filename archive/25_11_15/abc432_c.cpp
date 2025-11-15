// https://atcoder.jp/contests/abc432/tasks/abc432_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,y;
    cin >> n >> x >> y;
    vi a(n);
    cin >> a;
    sort(all(a));
    int mi=*a.begin(),mx=*a.rbegin();
    if (mx==mi) {
        print(mx*n);
        return 0;
    }
    int l=mx*x,r=mi*y;
    if (r<l) {
        print(-1);
        return 0;
    }
    int d=y-x;
    vi b=a;
    uniq(b);
    int m=b.size();
    int g=b[1]-b[0];
    for (int i=2; i<m; ++i) g=gcd(g,b[i]-b[i-1]);
    if ((y*mx-r)%(d*(mx-mi)/g)) {
        print(-1);
        return 0;
    }
    int ans=0;
    // r=(最小のa[i])*y の重量が作れるのでそれに揃える
    rep(i,n) {
        ans+=(r-x*a[i])/d;
    }
    print(ans);


    return 0;
}

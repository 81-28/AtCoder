// https://atcoder.jp/contests/joi2024ho/tasks/joi2024ho_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vi a(n);
    cin >> a;
    rep(i,n) a[i]%=t;
    sort(all(a));
    int mx=a[0]-a[n-1]+t;
    rep(i,n-1) chmax(mx,a[i+1]-a[i]);
    print((t-mx+1)/2);

    return 0;
}

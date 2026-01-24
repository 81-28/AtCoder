// https://atcoder.jp/contests/abc281/tasks/abc281_c

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


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vi a(n);
    cin >> a;
    vi sm(n+1,0);
    rep(i,n) sm[i+1]=sm[i]+a[i];
    t%=sm[n];
    auto it=upper_bound(all(sm),t);
    print(it-sm.begin()+1,t-*--it);

    return 0;
}

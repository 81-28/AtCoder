// https://atcoder.jp/contests/abc441/tasks/abc441_c

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

    int n,k,x;
    cin >> n >> k >> x;
    vi a(n);
    cin >> a;
    int ans=n-k;
    sort(all(a));
    vi sm(k+1,0);
    rep(i,k) sm[i+1]=sm[i]+a[k-1-i];
    auto it=lower_bound(all(sm),x);
    ans+=it-sm.begin();
    print(ans>n?-1:ans);

    return 0;
}

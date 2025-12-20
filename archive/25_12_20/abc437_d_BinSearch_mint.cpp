// https://atcoder.jp/contests/abc437/tasks/abc437_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    cin >> a >> b;
    sort(all(a));
    vi sm(n);
    sm[0]=a[0];
    for (int i=1; i<n; ++i) sm[i]=sm[i-1]+a[i];
    mint ans=0;
    for (int val:b) {
        auto it=lower_bound(all(a),val);
        int i=it-a.begin();
        ans+=val*i;
        ans-=val*(n-i);
        ans+=sm[n-1];
        if (i>0) ans-=sm[i-1]*2;
    }
    print(ans.val());

    return 0;
}

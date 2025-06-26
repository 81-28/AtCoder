// https://atcoder.jp/contests/abc367/tasks/abc367_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    a.insert(a.end(),all(a));
    vi r(n*2,0);
    rep(i,n*2-1) r[i+1]=(r[i]+a[i])%m;
    map<int,int> cnt;
    rep1(i,n-1) ++cnt[r[i]];
    int ans=0;
    rep(i,n) {
        ans+=cnt[r[i]];
        --cnt[r[i+1]];
        ++cnt[r[i+n]];
    }
    print(ans);

    return 0;
}

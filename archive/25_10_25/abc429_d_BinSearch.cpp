// https://atcoder.jp/contests/abc429/tasks/abc429_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,c;
    cin >> n >> m >> c;
    vi a(n);
    cin >> a;
    sort(all(a));
    // mp[i]:地点iにいる人数
    map<int,int> mp;
    rep(i,n) ++mp[a[i]];
    vi idx,cnt(1,0);
    int sm=0;
    for (auto[i,num]:mp) {
        idx.pb(i);
        sm+=num;
        cnt.pb(sm);
    }
    int l=cnt.size();
    rep1(i,l-1) cnt.pb(cnt[l-1]+cnt[i]);
    if (idx.size()==1) {
        print(m*n);
        return 0;
    }
    int ans=0,k=0;
    rep(i,n) {
        int j=(i+1)%n;
        int d=(a[j]-a[i]+m)%m;
        if (d==0) continue;
        // 基準
        int b=cnt[++k];
        auto it=lower_bound(all(cnt),b+c);
        ans+=(*it-b)*d;
    }
    print(ans);

    return 0;
}

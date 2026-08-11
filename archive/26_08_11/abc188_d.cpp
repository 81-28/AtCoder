// https://atcoder.jp/contests/abc188/tasks/abc188_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    cin >> n >> x;
    v<tuple<int,int,int>> t(n);
    vi a;
    for (auto&[l,r,c]:t) {
        cin >> l >> r >> c;
        a.pb(--l),a.pb(r);
    }
    sort(all(a)),uniq(a);
    int m=a.size();
    map<int,int> idx;
    rep(i,m) idx[a[i]]=i;
    vi sm(m,0);
    for (auto[l,r,c]:t) {
        sm[idx[l]]+=c;
        sm[idx[r]]-=c;
    }
    rep(i,m-1) sm[i+1]+=sm[i];
    int ans=0;
    rep(i,m-1) ans+=(a[i+1]-a[i])*min(x,sm[i]);
    print(ans);

    return 0;
}

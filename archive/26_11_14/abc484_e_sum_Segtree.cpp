// https://atcoder.jp/contests/abc484/tasks/abc484_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,l,r;
    cin >> n >> l >> r;
    vi a(n),b(n),c,s;
    cin >> a;
    int sm=0;
    rep(i,n) {
        if (!i) c.pb(0);
        else c.pb(c.back()-a[i-1]);
        sm+=a[i];
        b[i]=sm;
        s.pb(c.back());
    }
    sort(all(s)),uniq(s);
    int m=s.size();
    map<int,int> idx;
    rep(i,m) idx[s[i]]=i;
    segtree<S,op,e> t(m);
    int ans=0;
    rep(i,n) {
        int j=idx[c[i]];
        t.set(j,t.get(j)+1);
        auto itl=lower_bound(all(s),l-b[i]);
        auto itr=upper_bound(all(s),r-b[i]);
        ans+=t.prod(itl-s.begin(),itr-s.begin());
    }
    print(ans);

    return 0;
}

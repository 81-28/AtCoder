// https://atcoder.jp/contests/abc221/tasks/abc221_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    vi c;
    for (auto&[a,b]:p) {
        cin >> a >> b;
        c.pb(a);
        c.pb(a+b);
    }
    sort(all(c));
    uniq(c);
    int l=c.size();
    map<int,int> m;
    rep(i,l) m[c[i]]=i;
    vi sm(l,0);
    for (auto[a,b]:p) {
        ++sm[m[a]],--sm[m[a+b]];
    }
    for (int i=1; i<l; ++i) sm[i]+=sm[i-1];
    vi ans(n,0);
    rep(i,l-1) {
        // 人数,幅
        int cnt=sm[i],num=c[i+1]-c[i];
        if (!cnt) continue;
        ans[cnt-1]+=num;
    }
    print(ans);

    return 0;
}

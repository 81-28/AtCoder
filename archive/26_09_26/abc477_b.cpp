// https://atcoder.jp/contests/abc477/tasks/abc477_b

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max();
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    v<pii> p(n);
    rep(i,n) {
        auto&[x,j]=p[i];
        cin >> x;
        j=i;
    }
    p.pb({-INF,-1});
    p.pb({INF,-1});
    sort(all(p));
    vi ans;
    rep(l,n) {
        auto[a,i]=p[l];
        auto[b,j]=p[l+1];
        auto[c,k]=p[l+2];
        if (b-a<d) continue;
        if (c-b<d) continue;
        ans.pb(j+1);
    }
    sort(all(ans));
    print(ans.size());
    print(ans);

    return 0;
}

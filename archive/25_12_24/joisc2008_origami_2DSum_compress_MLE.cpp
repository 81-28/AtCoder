// https://atcoder.jp/contests/joisc2008/tasks/joisc2008_origami

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    cin >> n >> a >> b;
    v<tuple<int,int,int,int>> t(n);
    vi x,y;
    for (auto&[p,q,r,s]:t) {
        cin >> p >> q >> r >> s;
        --p,--q;
        x.pb(p),y.pb(q);
        x.pb(r),y.pb(s);
    }
    sort(all(x)),sort(all(y));
    uniq(x),uniq(y);
    unordered_map<int,int> idx,idy;
    int xs=x.size(),ys=y.size();
    rep(i,xs) idx[x[i]]=i;
    rep(i,ys) idy[y[i]]=i;
    vvi sm(xs,vi(ys,0));
    for (const auto&[p,q,r,s]:t) {
        int i=idx[p],j=idy[q];
        int k=idx[r],l=idy[s];
        ++sm[i][j];
        --sm[i][l];
        --sm[k][j];
        ++sm[k][l];
    }
    int mx=0;
    ll cnt=0;
    rep(i,xs-1)rep(j,ys-1) {
        if (i) sm[i][j]+=sm[i-1][j];
        if (j) sm[i][j]+=sm[i][j-1];
        if (i&&j) sm[i][j]-=sm[i-1][j-1];
        if (chmax(mx,sm[i][j])) cnt=(ll)(x[i+1]-x[i])*(y[j+1]-y[j]);
        else if (mx==sm[i][j]) cnt+=(ll)(x[i+1]-x[i])*(y[j+1]-y[j]);
    }
    print(mx);
    print(cnt);

    return 0;
}

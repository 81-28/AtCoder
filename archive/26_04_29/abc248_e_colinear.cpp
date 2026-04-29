// https://atcoder.jp/contests/abc248/tasks/abc248_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    if (k<2) {
        print("Infinity");
        return 0;
    }
    // b[i][j]:iとjの含む直線がカウント済みかどうか
    vvb b(n,vb(n,0));
    int ans=0;
    rep(i,n-1) {
        auto[x0,y0]=p[i];
        for(int j=i+1; j<n; ++j) {
            if (b[i][j]) continue;
            auto[x1,y1]=p[j];
            vi idx={i,j};
            for (int m=j+1; m<n; ++m) {
                auto[x,y]=p[m];
                if ((x1-x0)*(y-y0)==(y1-y0)*(x-x0)) idx.pb(m);
            }
            int l=idx.size();
            if (l>=k) ++ans;
            rep(x,l-1)for(int y=x+1; y<l; ++y) b[idx[x]][idx[y]]=1;
        }
    }
    print(ans);

    return 0;
}

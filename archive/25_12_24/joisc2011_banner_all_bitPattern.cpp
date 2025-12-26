// https://atcoder.jp/contests/joisc2011/tasks/joisc2011_banner

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    vvi c(h,vi(w));
    cin >> c;
    int ans=0;
    // a[i][j][k]:2行ij(i<j)に、同じ列で色の塗り方がk(k[l]:色lがある)であるものの個数
    v<vvi> cnt(h,vvi(h,vi(8,0)));
    rep(i,h-1)for (int j=i+1; j<h; ++j) {
        rep(k,w) ++cnt[i][j][(1<<c[i][k])|(1<<c[j][k])];
        int sm=0;
        // 011 (100 110)
        sm+=cnt[i][j][3]*(cnt[i][j][4]+cnt[i][j][6]);
        // 101 (010 011)
        sm+=cnt[i][j][5]*(cnt[i][j][2]+cnt[i][j][3]);
        // 110 (001 101)
        sm+=cnt[i][j][6]*(cnt[i][j][1]+cnt[i][j][5]);
        ans+=sm;
    }
    print(ans);

    return 0;
}

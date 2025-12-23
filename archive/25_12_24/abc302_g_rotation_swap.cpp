// https://atcoder.jp/contests/abc302/tasks/abc302_g

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    vi b=a;
    sort(all(b));
    // c[i][j] : i->j と変えたい個数
    vvi c(4,vi(4,0));
    int sm=0;
    rep(i,n) {
        if (a[i]==b[i]) continue;
        ++c[a[i]-1][b[i]-1];
        ++sm;
    }
    int ans=0;
    rep(i,3)for(int j=i+1; j<4; ++j) {
        int mi=min(c[i][j],c[j][i]);
        if (mi==0) continue;
        c[i][j]-=mi;
        c[j][i]-=mi;
        ans+=mi;
        sm-=mi*2;
    }
    rep(i,4) rep(j,4) {
        if (i==j) continue;
        rep(k,4) {
            if (k==i || k==j) continue;
            int mi=min({c[i][j],c[j][k],c[k][i]});
            if (mi==0) continue;
            c[i][j]-=mi;
            c[j][k]-=mi;
            c[k][i]-=mi;
            ans+=mi*2;
            sm-=mi*3;
        }
    }
    ans+=sm*3/4;
    print(ans);

    return 0;
}

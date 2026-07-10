// https://atcoder.jp/contests/abc203/tasks/abc203_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,k;
    cin >> n >> k;
    vvi a(n,vi(n));
    cin >> a;
    int mx=0;
    rep(i,n)rep(j,n) chmax(mx,a[i][j]);
    // (l,r] 中央値がl以下である範囲か存在せず、r以下である範囲が存在する
    int l=-1,r=mx;
    int m=(k*k+1)/2;
    while (l+1<r) {
        int mid=(l+r)/2;
        // 中央値がmid以下である範囲が1つ以上あるかどうか
        // mid以下の個数の累積和
        vvi sm(n+1,vi(n+1,0));
        rep1(i,n)rep1(j,n) sm[i][j] = (a[i-1][j-1]<=mid) + sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
        bool ok=0;
        rep(i,n+1-k) {
            rep(j,n+1-k) {
                int cnt=sm[i+k][j+k]-sm[i][j+k]-sm[i+k][j]+sm[i][j];
                if (cnt>=m) {
                    ok=1;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) r=mid;
        else l=mid;
    }
    print(r);

    return 0;
}

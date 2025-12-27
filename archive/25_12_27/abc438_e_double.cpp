// https://atcoder.jp/contests/abc438/tasks/abc438_e

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

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    int m=30;
    // cnt[i][j]:2^i回の操作後にバケツjに入っている水の量
    vvi cnt(m,vi(n));
    rep(i,n) cnt[0][i]=i+1;
    // pos[i][j]:2^i回の操作後にバケツjのある位置
    vvi pos(m,vi(n));
    rep(i,n) pos[0][i]=a[i]-1;
    rep1(i,m-1) {
        rep(j,n) {
            pos[i][j]=pos[i-1][pos[i-1][j]];
            cnt[i][j]=cnt[i-1][j]+cnt[i-1][pos[i-1][j]];
        }
    }
    while (q--) {
        int t,b;
        cin >> t >> b;
        --b;
        int ans=0;
        rep(i,m) {
            if ((t>>i)&1) {
                ans+=cnt[i][b];
                b=pos[i][b];
            }
        }
        print(ans);
    }


    return 0;
}

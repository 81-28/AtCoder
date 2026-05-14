// https://atcoder.jp/contests/abc241/tasks/abc241_e

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

int int_log2(int n) {
    int i=-1;
    for(;n>0;n>>=1)++i;
    return i;
}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    int m=int_log2(k)+1;
    // cnt[i][j]:xの剰余がjの時に、2^i回の操作をしたら加算される量
    vvi cnt(m,vi(n));
    cnt[0]=a;
    rep1(i,m-1) {
        rep(j,n) {
            int nxt=(j+cnt[i-1][j])%n;
            cnt[i][j]=cnt[i-1][j]+cnt[i-1][nxt];
        }
    }
    int x=0;
    rep(i,m) {
        if ((k>>i)&1) x+=cnt[i][x%n];
    }
    print(x);

    return 0;
}

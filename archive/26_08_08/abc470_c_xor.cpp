// https://atcoder.jp/contests/abc470/tasks/abc470_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int mx=20;
vvi b;
// val=x の要素を追加/削除したとき、各余りの個数の偶奇を反転する
void f(int x) {
    rep(i,mx) {
        int mask=(1LL<<i)-1;
        int r=x&mask;
        b[i][r]^=1;
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // クエリ2を行った回数
    int base=0;
    // a[i]>0の時、val[i]=a[i]+base
    vi val(n,0);
    // cnt[i]: baseがiになったとき0になる要素の数
    vi cnt(q+1,0);
    // b[i][j]: val % 2^i = j である要素の個数の偶奇
    b=vvi(mx);
    rep(i,mx) b[i]=vi(1LL<<i);

    int ans=0;
    while (q--) {
        int m,x;
        cin >> m;
        if (m&1) {
            cin >> x;
            --x;
            int old=0;
            if (val[x]>base) {
                old=val[x]-base;
                --cnt[val[x]];
                f(val[x]);
                ++val[x];
            } else {
                val[x]=base+1;
            }
            ans^=old;
            ans^=old+1;
            ++cnt[val[x]];
            f(val[x]);
        } else {
            rep(i,mx) {
                int mask=(1LL<<i)-1;
                int r=base&mask;
                if (b[i][r]) ans^=(1LL<<i);
            }
            ++base;
            if (cnt[base]&1) f(base);
        }
        print(ans);
    }

    return 0;
}

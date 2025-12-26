// https://atcoder.jp/contests/joig2025-open/tasks/joig2025_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string t;
    cin >> n >> q >> t;

    vi tri(n+1,1);
    rep1(i,n) tri[i]=tri[i-1]*3;
    int l=tri[n];

    // 子の多数決の結果を保持する三分木セグ木
    vvi seg(n+1);
    rep(i,n+1) seg[i]=vi(tri[i]);
    rep(i,l) seg[n][i]=t[i]-'A';
    for(int i=n-1; i>=0; --i) {
        rep(j,tri[i]) {
            int sm=0;
            rep(k,3) sm+=seg[i+1][j*3+k];
            seg[i][j]=sm>1;
        }
    }
    while (q--) {
        int p;
        cin >> p;
        --p;
        seg[n][p]^=1;
        for (int i=n-1; i>=0; --i) {
            p/=3;
            int sm=0;
            rep(k,3) sm+=seg[i+1][p*3+k];
            seg[i][p]=sm>1;
        }
        print(char('A'+seg[0][0]));
    }

    return 0;
}

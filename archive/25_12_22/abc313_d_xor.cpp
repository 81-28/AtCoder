// https://atcoder.jp/contests/abc313/tasks/abc313_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    // sm[i]:a[1]~a[k+1]までの和から、a[i]を引いたもの
    vi sm(k+2,0);
    // 全ての和　kが奇数なので、a[i]は奇数回xor加算され、それぞれ1回加算された時と等しくなる
    int sma=0;
    rep1(i,k+1) {
        cout<<'?';
        rep1(j,k+1) {
            if (j!=i) cout<<' '<<j;
        }
        cout<<endl;
        int t;
        cin >> t;
        sm[i]=t;
        sma^=t;
    }
    vi a(n+1);
    rep1(i,k+1) a[i]=sma!=sm[i];

    for (int i=k+2; i<=n; ++i) {
        cout<<'?';
        rep1(j,k-1) cout<<' '<<j;
        cout<<' '<<i<<endl;
        int t;
        cin >> t;
        a[i]=(sm[k+1]!=t)^a[k];
    }
    cout<<'!';
    rep1(i,n) cout<<' '<<a[i];
    cout<<endl;

    return 0;
}

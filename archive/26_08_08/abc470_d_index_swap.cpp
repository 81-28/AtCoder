// https://atcoder.jp/contests/abc470/tasks/abc470_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vvi p(2,vi(n+1));
    rep1(i,n) cin >> p[0][i];
    rep1(i,n) p[1][p[0][i]]=i;
    bool b=0;
    while (q--) {
        int m,x,y;
        cin >> m;
        if (m&1) {
            cin >> x >> y;
            int tmp=p[b][x];
            p[b][x]=p[b][y];
            p[b][y]=tmp;
            p[!b][p[b][x]]=x;
            p[!b][p[b][y]]=y;
        } else b^=1;
    }
    rep1(i,n) cout<<p[b][i]<<' ';
    cout<<endl;

    return 0;
}

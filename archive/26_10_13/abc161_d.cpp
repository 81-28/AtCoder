// https://atcoder.jp/contests/abc161/tasks/abc161_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化


// l[a][b]:長さaで、左端がbである個数
vvi l(11,vi(11,0));

int h(int& i,int& k) {
    for (i=1; i<11; ++i)rep1(j,9) {
        if (l[i][j]>=k) return j;
        k-=l[i][j];
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    rep(i,10) l[1][i]=1;
    for (int i=1; i<11; ++i) {
        rep(j,10) {
            if (j) l[i][j]+=l[i-1][j-1];
            l[i][j]+=l[i-1][j]+l[i-1][j+1];
        }
    }

    int i,k;
    cin >> k;
    vi ans(1,h(i,k));
    for (; i>1; --i) {
        int t=ans.back();
        vi a(1,0);
        for (int j=t-1; j<t+2; ++j) {
            if (j<0) continue;
            a.pb(a.back()+l[i-1][j]);
        }
        auto it=lower_bound(all(a),k);
        --it;
        ans.pb(t+3-(a.end()-it));
        k-=*it;
    }
    for (int val:ans) cout<<val;
    cout<<endl;

    return 0;
}

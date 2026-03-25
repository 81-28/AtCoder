// https://atcoder.jp/contests/abc274/tasks/abc274_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi ans(1,0);
    rep(i,n) {
        int a;
        cin >> a;
        rep(j,2) ans.pb(ans[a-1]+1);
    }
    rep(i,n*2+1) cout<<ans[i]<<' ';
    cout<<endl;

    return 0;
}

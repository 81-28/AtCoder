// https://atcoder.jp/contests/abc254/tasks/abc254_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n+1,0);
    a[1]=1;
    rep1(i,n) {
        rep1(j,i) cout<<a[j]<<' ';
        cout<<endl;
        for (int j=n; j; --j) a[j]+=a[j-1];
    }

    return 0;
}
